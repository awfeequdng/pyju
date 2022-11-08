#include <Client/ClientBase.h>

#include <iostream>
#include <iomanip>
#include <string_view>
#include <filesystem>
#include <map>
#include <unordered_map>
#include <base/argsToConfig.h>
#include <Common/DateLUT.h>
#include <Common/LocalDate.h>
#include <Common/MemoryTracker.h>
#include <base/LineReader.h>
#include <base/scope_guard_safe.h>
#include <Common/Exception.h>
#include <Common/getNumberOfPhysicalCPUCores.h>
#include <Common/typeid_cast.h>
#include <Common/config.h>

#include <Common/config_version.h>
#include <Common/UTF8Helpers.h>
#include <Common/TerminalSize.h>
#include <Common/clearPasswordFromCommandLine.h>
#include <Common/StringUtils/StringUtils.h>
#include <Common/filesystemHelpers.h>

#include <Client/ClientBaseHelpers.h>

#include <IO/WriteBufferFromOStream.h>
#include <IO/CompressionMethod.h>
#include <IO/ReadHelpers.h>
#include <boost/algorithm/string/replace.hpp>


namespace fs = std::filesystem;
using namespace std::literals;


namespace CurrentMetrics
{
    extern const Metric MemoryTracking;
}

namespace PYJU
{

static const NameSet exit_strings
{
    "exit", "quit", "logout", "учше", "йгше", "дщпщге",
    "exit;", "quit;", "logout;", "учшеж", "йгшеж", "дщпщгеж",
    "q", "й", "\\q", "\\Q", "\\й", "\\Й", ":q", "Жй"
};

static const std::initializer_list<std::pair<String, String>> backslash_aliases
{
    { "\\l", "SHOW DATABASES" },
    { "\\d", "SHOW TABLES" },
    { "\\c", "USE" },
};


namespace ErrorCodes
{
    extern const int BAD_ARGUMENTS;
    extern const int DEADLOCK_AVOIDED;
    extern const int CLIENT_OUTPUT_FORMAT_SPECIFIED;
    extern const int UNKNOWN_PACKET_FROM_SERVER;
    extern const int NO_DATA_TO_INSERT;
    extern const int UNEXPECTED_PACKET_FROM_SERVER;
    extern const int INVALID_USAGE_OF_INPUT;
    extern const int CANNOT_SET_SIGNAL_HANDLER;
    extern const int UNRECOGNIZED_ARGUMENTS;
    extern const int LOGICAL_ERROR;
}

}

namespace ProfileEvents
{
    extern const Event UserTimeMicroseconds;
    extern const Event SystemTimeMicroseconds;
}

namespace PYJU
{

std::atomic_flag exit_on_signal = ATOMIC_FLAG_INIT;

class QueryInterruptHandler : private boost::noncopyable
{
public:
    QueryInterruptHandler() { exit_on_signal.clear(); }

    ~QueryInterruptHandler() { exit_on_signal.test_and_set(); }

    static bool cancelled() { return exit_on_signal.test(); }
};

/// This signal handler is set only for sigint.
void interruptSignalHandler(int signum)
{
    if (exit_on_signal.test_and_set())
        _exit(signum);
}


ClientBase::~ClientBase() = default;
ClientBase::ClientBase() = default;


void ClientBase::setupSignalHandler()
{
     exit_on_signal.test_and_set();

     struct sigaction new_act;
     memset(&new_act, 0, sizeof(new_act));

     new_act.sa_handler = interruptSignalHandler;
     new_act.sa_flags = 0;

#if defined(OS_DARWIN)
    sigemptyset(&new_act.sa_mask);
#else
     if (sigemptyset(&new_act.sa_mask))
        throw Exception(ErrorCodes::CANNOT_SET_SIGNAL_HANDLER, "Cannot set signal handler.");
#endif

     if (sigaction(SIGINT, &new_act, nullptr))
        throw Exception(ErrorCodes::CANNOT_SET_SIGNAL_HANDLER, "Cannot set signal handler.");
}

bool ClientBase::processScriptText(const String & text, std::function<int(std::string)>pyju_main_script)
{
    if (exit_strings.end() != exit_strings.find(trim(text, [](char c) { return isWhitespaceASCII(c) || c == ';'; })))
        return false;

    // std::cout << text << std::endl;
    pyju_main_script(text);
    return true;
}

String ClientBase::prompt() const
{
    return "pyju :]";
}

void ClientBase::runInteractive(std::function<int(std::string)> pyju_main_script)
{
    if (print_time_to_stderr)
        throw Exception("time option could be specified only in non-interactive mode", ErrorCodes::BAD_ARGUMENTS);

    /// Initialize DateLUT here to avoid counting time spent here as query execution time.
    const auto local_tz = DateLUT::instance().getTimeZone();

    suggest.emplace();

    if (home_path.empty())
    {
        const char * home_path_cstr = getenv("HOME");
        if (home_path_cstr)
            home_path = home_path_cstr;
    }

    /// Load command history if present.
    if (config().has("history_file"))
        history_file = config().getString("history_file");
    else
    {
        auto * history_file_from_env = getenv("PYJU_HISTORY_FILE");
        if (history_file_from_env)
            history_file = history_file_from_env;
        else if (!home_path.empty())
            history_file = home_path + "/.pyju-history";
    }

    if (!history_file.empty() && !fs::exists(history_file))
    {
        /// Avoid TOCTOU issue.
        try
        {
            FS::createFile(history_file);
        }
        catch (const ErrnoException & e)
        {
            if (e.getErrno() != EEXIST)
                throw;
        }
    }

    LineReader::Patterns query_extenders = {"\\"};
    LineReader::Patterns query_delimiters = {";", "\\G"};

#if USE_REPLXX
    replxx::Replxx::highlighter_callback_t highlight_callback{};
    if (config().getBool("highlight", true))
        highlight_callback = highlight;

    // ReplxxLineReader lr(*suggest, history_file, config().has("multiline"), query_extenders, query_delimiters, highlight_callback);
    // not support multiline
    ReplxxLineReader lr(*suggest, history_file, false, query_extenders, query_delimiters, highlight_callback);
#else
    LineReader lr(history_file, config().has("multiline"), query_extenders, query_delimiters);
#endif

    /// Enable bracketed-paste-mode so that we are able to paste multiline queries as a whole.
    lr.enableBracketedPaste();

    do
    {
        auto input = lr.readLine(prompt(), ":-] ");
        if (input.empty())
            break;

        has_vertical_output_suffix = false;
        if (input.ends_with("\\G"))
        {
            input.resize(input.size() - 2);
            has_vertical_output_suffix = true;
        }

        for (const auto& [alias, command] : backslash_aliases)
        {
            auto it = std::search(input.begin(), input.end(), alias.begin(), alias.end());
            if (it != input.end() && std::all_of(input.begin(), it, isWhitespaceASCII))
            {
                it += alias.size();
                if (it == input.end() || isWhitespaceASCII(*it))
                {
                    String new_input = command;
                    // append the rest of input to the command
                    new_input.append(it, input.end());
                    input = std::move(new_input);
                    break;
                }
            }
        }

        try
        {
            if (!processScriptText(input, pyju_main_script))
                break;
        }
        catch (const Exception & e)
        {
            /// We don't need to handle the test hints in the interactive mode.
            std::cerr << "Exception on client:" << std::endl << getExceptionMessage(e, print_stack_trace, true) << std::endl << std::endl;
        }

    }
    while (true);

    if (isNewYearMode())
        std::cout << "Happy new year." << std::endl;
    else if (isChineseNewYearMode(local_tz))
        std::cout << "Happy Chinese new year. 春节快乐!" << std::endl;
    else
        std::cout << "Bye." << std::endl;
}

void ClientBase::runNonInteractive(std::function<int(int, char **)> pyju_main)
{
    pyju_main(argc_, argv_);
}

void ClientBase::clearTerminal()
{
    /// Clear from cursor until end of screen.
    /// It is needed if garbage is left in terminal.
    /// Show cursor. It can be left hidden by invocation of previous programs.
    /// A test for this feature: perl -e 'print "x"x100000'; echo -ne '\033[0;0H\033[?25l'; clickhouse-client
    std::cout << "\033[0J" "\033[?25h";
}


void ClientBase::showClientVersion()
{
    std::cout << PYJU_NAME << " " + getName() + " version " << VERSION_STRING << VERSION_OFFICIAL << "." << std::endl;
}


void ClientBase::readArguments(int argc, char ** argv, Arguments & common_arguments)
{
    for (int arg_num = 1; arg_num < argc; ++arg_num) {
        const char * arg = argv[arg_num];
        if (arg_num == 1) script_file = arg;

        common_arguments.emplace_back(arg);
    }
}

void ClientBase::parseAndCheckOptions(OptionsDescription & options_description, po::variables_map & options, Arguments & arguments)
{
    /// Parse main commandline options.
    auto parser = po::command_line_parser(arguments).options(options_description.main_description.value()).allow_unregistered();
    po::parsed_options parsed = parser.run();

    po::store(parsed, options);

    if (arguments.size() > 1) {
        is_interactive = false;
    } else {
        is_interactive = true;
    }
}

void ClientBase::init(int argc, char ** argv)
{
    namespace po = boost::program_options;

    /// Don't parse options with Poco library, we prefer neat boost::program_options.
    stopOptionsProcessing();

    stdin_is_a_tty = isatty(STDIN_FILENO);
    stdout_is_a_tty = isatty(STDOUT_FILENO);
    terminal_width = getTerminalWidth();

    Arguments common_arguments{""}; /// 0th argument is ignored.

    readArguments(argc, argv, common_arguments);

    po::variables_map options;
    OptionsDescription options_description;
    options_description.main_description.emplace(createOptionsDescription("Main options", terminal_width));

    /// Common options for clickhouse-client and clickhouse-local.
    options_description.main_description->add_options()
        ("help", "produce help message")
        ("version,V", "print version information and exit")
        ("version-clean", "print version in machine-readable format and exit")
        ("config-file,C", po::value<std::string>(), "config-file path")
        ("history_file", po::value<std::string>(), "path to history file")

        ("time,t", "print script execution time to stderr in non-interactive mode (for benchmarks)")

        ("echo", "in batch mode, script query before execution")
        ("verbose", "print script and other debugging info")

        ("log-level", po::value<std::string>(), "log level")

        ("multiline,m", "multiline")

        ("highlight", po::value<bool>()->default_value(true), "enable or disable basic syntax highlight in interactive command line")

        ("stacktrace", "print stack traces of exceptions")
        ("hardware-utilization", "print hardware utilization information in progress bar")
        ("print-profile-events", po::value(&profile_events.print)->zero_tokens(), "Printing ProfileEvents packets")
        ("profile-events-delay-ms", po::value<UInt64>()->default_value(profile_events.delay_ms), "Delay between printing `ProfileEvents` packets (-1 - print only totals, 0 - print every single packet)")

        ("interactive", "Process script-file and start interactive mode")
        ("pager", po::value<std::string>(), "Pipe all output into this command (less or similar)")
    ;

    auto getter = [](const auto & op)
    {
        String op_long_name = op->long_name();
        return "--" + String(op_long_name);
    };

    if (options_description.main_description)
    {
        const auto & main_options = options_description.main_description->options();
        std::transform(main_options.begin(), main_options.end(), std::back_inserter(cmd_options), getter);
    }

    parseAndCheckOptions(options_description, options, common_arguments);
    po::notify(options);

    if (options.count("version") || options.count("V"))
    {
        showClientVersion();
        exit(0);
    }

    if (options.count("version-clean"))
    {
        std::cout << VERSION_STRING;
        exit(0);
    }

    /// Output of help message.
    if (options.count("help")
        || (options.count("host") && options["host"].as<std::string>() == "elp")) /// If user writes -help instead of --help.
    {
        printHelpMessage(options_description);
        exit(0);
    }

    /// Common options for clickhouse-client and clickhouse-local.
    if (options.count("time"))
        print_time_to_stderr = true;
    if (options.count("multiline"))
        config().setBool("multiline", true);
    if (options.count("stacktrace"))
        config().setBool("stacktrace", true);
    if (options.count("print-profile-events"))
        config().setBool("print-profile-events", true);
    if (options.count("profile-events-delay-ms"))
        config().setInt("profile-events-delay-ms", options["profile-events-delay-ms"].as<UInt64>());
    if (options.count("echo"))
        config().setBool("echo", true);
    if (options.count("highlight"))
        config().setBool("highlight", options["highlight"].as<bool>());
    if (options.count("history_file"))
        config().setString("history_file", options["history_file"].as<std::string>());
    if (options.count("verbose"))
        config().setBool("verbose", true);
    if (options.count("interactive"))
        config().setBool("interactive", true);
    if (options.count("log-level"))
        Poco::Logger::root().setLevel(options["log-level"].as<std::string>());

    profile_events.print = options.count("print-profile-events");
    profile_events.delay_ms = options["profile-events-delay-ms"].as<UInt64>();

    clearPasswordFromCommandLine(argc, argv);
    argc_ = argc;
    argv_ = argv;

    /// Limit on total memory usage
    size_t max_client_memory_usage = config().getInt64("max_memory_usage_in_client", 0 /*default value*/);
    if (max_client_memory_usage != 0)
    {
        total_memory_tracker.setHardLimit(max_client_memory_usage);
        total_memory_tracker.setDescription("(total)");
        total_memory_tracker.setMetric(CurrentMetrics::MemoryTracking);
    }
}

}

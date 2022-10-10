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


void ClientBase::processTextAsSingleQuery(const String & full_query)
{
    std::cout << full_query << std::endl;
}


bool ClientBase::processQueryText(const String & text)
{
    if (exit_strings.end() != exit_strings.find(trim(text, [](char c) { return isWhitespaceASCII(c) || c == ';'; })))
        return false;

    processTextAsSingleQuery(text);

    return true;
}


String ClientBase::prompt() const
{
    return "pyju :]";
}


void ClientBase::initQueryIdFormats()
{
    if (!query_id_formats.empty())
        return;

    /// Initialize query_id_formats if any
    if (config().has("query_id_formats"))
    {
        Poco::Util::AbstractConfiguration::Keys keys;
        config().keys("query_id_formats", keys);
        for (const auto & name : keys)
            query_id_formats.emplace_back(name + ":", config().getString("query_id_formats." + name));
    }

    if (query_id_formats.empty())
        query_id_formats.emplace_back("Query id:", " {query_id}\n");
}


void ClientBase::runInteractive()
{
    if (config().has("query_id"))
        throw Exception("query_id could be specified only in non-interactive mode", ErrorCodes::BAD_ARGUMENTS);
    if (print_time_to_stderr)
        throw Exception("time option could be specified only in non-interactive mode", ErrorCodes::BAD_ARGUMENTS);

    initQueryIdFormats();

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
    ReplxxLineReader lr(*suggest, history_file, true, query_extenders, query_delimiters, highlight_callback);
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
                    // for parameters support, e.g. \c db_name -> USE db_name
                    new_input.append(it, input.end());
                    input = std::move(new_input);
                    break;
                }
            }
        }

        try
        {
            if (!processQueryText(input))
                break;
        }
        catch (const Exception & e)
        {
            /// We don't need to handle the test hints in the interactive mode.
            std::cerr << "Exception on client:" << std::endl << getExceptionMessage(e, print_stack_trace, true) << std::endl << std::endl;
            client_exception = std::make_unique<Exception>(e);
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


void ClientBase::runNonInteractive()
{
    if (delayed_interactive)
        initQueryIdFormats();

    if (!queries_files.empty())
    {
        auto process_query_from_file = [&](const String & file)
        {
            String queries_from_file;

            ReadBufferFromFile in(file);
            readStringUntilEOF(queries_from_file, in);

            return processQueryText(queries_from_file);
        };

        for (const auto & queries_file : queries_files)
        {
            for (const auto & interleave_file : interleave_queries_files)
                if (!process_query_from_file(interleave_file))
                    return;

            if (!process_query_from_file(queries_file))
                return;
        }

        return;
    }

    String text;
    if (config().has("query"))
    {
        text += config().getRawString("query"); /// Poco configuration should not process substitutions in form of ${...} inside query.
    }
    else
    {
        /// If 'query' parameter is not set, read a query from stdin.
        /// The query is read entirely into memory (streaming is disabled).
        ReadBufferFromFileDescriptor in(STDIN_FILENO);
        readStringUntilEOF(text, in);
    }


    processQueryText(text);
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
    std::cout << DBMS_NAME << " " + getName() + " version " << VERSION_STRING << VERSION_OFFICIAL << "." << std::endl;
}


void ClientBase::readArguments(
    int argc,
    char ** argv,
    Arguments & common_arguments,
    std::vector<Arguments> & external_tables_arguments,
    std::vector<Arguments> & hosts_and_ports_arguments)
{
    /** We allow different groups of arguments:
        * - common arguments;
        * - arguments for any number of external tables each in form "--external args...",
        *   where possible args are file, name, format, structure, types;
        * - param arguments for prepared statements.
        * Split these groups before processing.
        */

    bool in_external_group = false;

    std::string prev_host_arg;
    std::string prev_port_arg;

    for (int arg_num = 1; arg_num < argc; ++arg_num)
    {
        const char * arg = argv[arg_num];

        if (arg == "--external"sv)
        {
            in_external_group = true;
            external_tables_arguments.emplace_back(Arguments{""});
        }
        /// Options with value after equal sign.
        else if (in_external_group
            && (0 == strncmp(arg, "--file=", strlen("--file=")) || 0 == strncmp(arg, "--name=", strlen("--name="))
                || 0 == strncmp(arg, "--format=", strlen("--format=")) || 0 == strncmp(arg, "--structure=", strlen("--structure="))
                || 0 == strncmp(arg, "--types=", strlen("--types="))))
        {
            external_tables_arguments.back().emplace_back(arg);
        }
        /// Options with value after whitespace.
        else if (in_external_group
            && (arg == "--file"sv || arg == "--name"sv || arg == "--format"sv
                || arg == "--structure"sv || arg == "--types"sv))
        {
            if (arg_num + 1 < argc)
            {
                external_tables_arguments.back().emplace_back(arg);
                ++arg_num;
                arg = argv[arg_num];
                external_tables_arguments.back().emplace_back(arg);
            }
            else
                break;
        }
        else
        {
            in_external_group = false;

            /// Parameter arg after underline.
            if (startsWith(arg, "--param_"))
            {
                const char * param_continuation = arg + strlen("--param_");
                const char * equal_pos = strchr(param_continuation, '=');

                if (equal_pos == param_continuation)
                    throw Exception("Parameter name cannot be empty", ErrorCodes::BAD_ARGUMENTS);

                if (equal_pos)
                {
                    /// param_name=value
                }
                else
                {
                    /// param_name value
                    ++arg_num;
                    if (arg_num >= argc)
                        throw Exception("Parameter requires value", ErrorCodes::BAD_ARGUMENTS);
                    arg = argv[arg_num];
                }
            }
            else if (startsWith(arg, "--host") || startsWith(arg, "-h"))
            {
                std::string host_arg;
                /// --host host
                if (arg == "--host"sv || arg == "-h"sv)
                {
                    ++arg_num;
                    if (arg_num >= argc)
                        throw Exception("Host argument requires value", ErrorCodes::BAD_ARGUMENTS);
                    arg = argv[arg_num];
                    host_arg = "--host=";
                    host_arg.append(arg);
                }
                else
                    host_arg = arg;

                /// --port port1 --host host1
                if (!prev_port_arg.empty())
                {
                    hosts_and_ports_arguments.push_back({host_arg, prev_port_arg});
                    prev_port_arg.clear();
                }
                else
                {
                    /// --host host1 --host host2
                    if (!prev_host_arg.empty())
                        hosts_and_ports_arguments.push_back({prev_host_arg});

                    prev_host_arg = host_arg;
                }
            }
            else if (startsWith(arg, "--port"))
            {
                std::string port_arg = arg;
                /// --port port
                if (arg == "--port"sv)
                {
                    port_arg.push_back('=');
                    ++arg_num;
                    if (arg_num >= argc)
                        throw Exception("Port argument requires value", ErrorCodes::BAD_ARGUMENTS);
                    arg = argv[arg_num];
                    port_arg.append(arg);
                }

                /// --host host1 --port port1
                if (!prev_host_arg.empty())
                {
                    hosts_and_ports_arguments.push_back({port_arg, prev_host_arg});
                    prev_host_arg.clear();
                }
                else
                {
                    /// --port port1 --port port2
                    if (!prev_port_arg.empty())
                        hosts_and_ports_arguments.push_back({prev_port_arg});

                    prev_port_arg = port_arg;
                }
            }
            else
                common_arguments.emplace_back(arg);
        }
    }
    if (!prev_host_arg.empty())
        hosts_and_ports_arguments.push_back({prev_host_arg});
    if (!prev_port_arg.empty())
        hosts_and_ports_arguments.push_back({prev_port_arg});
}

void ClientBase::parseAndCheckOptions(OptionsDescription & options_description, po::variables_map & options, Arguments & arguments)
{
    /// Parse main commandline options.
    auto parser = po::command_line_parser(arguments).options(options_description.main_description.value()).allow_unregistered();
    po::parsed_options parsed = parser.run();

    /// Check unrecognized options without positional options.
    auto unrecognized_options = po::collect_unrecognized(parsed.options, po::collect_unrecognized_mode::exclude_positional);
    if (!unrecognized_options.empty())
    {
        auto hints = this->getHints(unrecognized_options[0]);
        if (!hints.empty())
            // throw Exception(ErrorCodes::UNRECOGNIZED_ARGUMENTS, "Unrecognized option '{}'. Maybe you meant {}", unrecognized_options[0], toString(hints[0]));
            throw Exception(ErrorCodes::UNRECOGNIZED_ARGUMENTS, "Unrecognized option '{}'. Maybe you meant {}, not full implemented", unrecognized_options[0], hints[0]);

        throw Exception(ErrorCodes::UNRECOGNIZED_ARGUMENTS, "Unrecognized option '{}'", unrecognized_options[0]);
    }

    /// Check positional options (options after ' -- ', ex: clickhouse-client -- <options>).
    unrecognized_options = po::collect_unrecognized(parsed.options, po::collect_unrecognized_mode::include_positional);
    if (unrecognized_options.size() > 1)
        throw Exception(ErrorCodes::BAD_ARGUMENTS, "Positional options are not supported.");

    po::store(parsed, options);
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
    std::vector<Arguments> external_tables_arguments;
    std::vector<Arguments> hosts_and_ports_arguments;

    readArguments(argc, argv, common_arguments, external_tables_arguments, hosts_and_ports_arguments);

    po::variables_map options;
    OptionsDescription options_description;
    options_description.main_description.emplace(createOptionsDescription("Main options", terminal_width));

    /// Common options for clickhouse-client and clickhouse-local.
    options_description.main_description->add_options()
        ("help", "produce help message")
        ("version,V", "print version information and exit")
        ("version-clean", "print version in machine-readable format and exit")

        ("config-file,C", po::value<std::string>(), "config-file path")
        ("queries-file", po::value<std::vector<std::string>>()->multitoken(),
            "file path with queries to execute; multiple files can be specified (--queries-file file1 file2...)")
        ("database,d", po::value<std::string>(), "database")
        ("history_file", po::value<std::string>(), "path to history file")

        ("query,q", po::value<std::string>(), "query")
        ("stage", po::value<std::string>()->default_value("complete"), "Request query processing up to specified stage: complete,fetch_columns,with_mergeable_state,with_mergeable_state_after_aggregation,with_mergeable_state_after_aggregation_and_limit")
        ("query_id", po::value<std::string>(), "query_id")
        ("progress", "print progress of queries execution")

        ("disable_suggestion,A", "Disable loading suggestion data. Note that suggestion data is loaded asynchronously through a second connection to ClickHouse server. Also it is reasonable to disable suggestion if you want to paste a query with TAB characters. Shorthand option -A is for those who get used to mysql client.")
        ("time,t", "print query execution time to stderr in non-interactive mode (for benchmarks)")

        ("echo", "in batch mode, print query before execution")
        ("verbose", "print query and other debugging info")

        ("log-level", po::value<std::string>(), "log level")

        ("multiline,m", "multiline")
        ("multiquery,n", "multiquery")

        ("suggestion_limit", po::value<int>()->default_value(10000),
            "Suggestion limit for how many databases, tables and columns to fetch.")

        ("format,f", po::value<std::string>(), "default output format")
        ("vertical,E", "vertical output format, same as --format=Vertical or FORMAT Vertical or \\G at end of command")
        ("highlight", po::value<bool>()->default_value(true), "enable or disable basic syntax highlight in interactive command line")

        ("ignore-error", "do not stop processing in multiquery mode")
        ("stacktrace", "print stack traces of exceptions")
        ("hardware-utilization", "print hardware utilization information in progress bar")
        ("print-profile-events", po::value(&profile_events.print)->zero_tokens(), "Printing ProfileEvents packets")
        ("profile-events-delay-ms", po::value<UInt64>()->default_value(profile_events.delay_ms), "Delay between printing `ProfileEvents` packets (-1 - print only totals, 0 - print every single packet)")

        ("interactive", "Process queries-file or --query query and start interactive mode")
        ("pager", po::value<std::string>(), "Pipe all output into this command (less or similar)")
        ("max_memory_usage_in_client", po::value<int>(), "Set memory limit in client/local server")
    ;

    addOptions(options_description);

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

    if (options_description.external_description)
    {
        const auto & external_options = options_description.external_description->options();
        std::transform(external_options.begin(), external_options.end(), std::back_inserter(cmd_options), getter);
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
    if (options.count("query"))
        config().setString("query", options["query"].as<std::string>());
    if (options.count("query_id"))
        config().setString("query_id", options["query_id"].as<std::string>());
    if (options.count("database"))
        config().setString("database", options["database"].as<std::string>());
    if (options.count("config-file"))
        config().setString("config-file", options["config-file"].as<std::string>());
    if (options.count("queries-file"))
        queries_files = options["queries-file"].as<std::vector<std::string>>();
    if (options.count("multiline"))
        config().setBool("multiline", true);
    if (options.count("multiquery"))
        config().setBool("multiquery", true);
    if (options.count("ignore-error"))
        config().setBool("ignore-error", true);
    if (options.count("format"))
        config().setString("format", options["format"].as<std::string>());
    if (options.count("vertical"))
        config().setBool("vertical", true);
    if (options.count("stacktrace"))
        config().setBool("stacktrace", true);
    if (options.count("print-profile-events"))
        config().setBool("print-profile-events", true);
    if (options.count("profile-events-delay-ms"))
        config().setInt("profile-events-delay-ms", options["profile-events-delay-ms"].as<UInt64>());
    if (options.count("progress"))
        config().setBool("progress", true);
    if (options.count("echo"))
        config().setBool("echo", true);
    if (options.count("disable_suggestion"))
        config().setBool("disable_suggestion", true);
    if (options.count("suggestion_limit"))
        config().setInt("suggestion_limit", options["suggestion_limit"].as<int>());
    if (options.count("highlight"))
        config().setBool("highlight", options["highlight"].as<bool>());
    if (options.count("history_file"))
        config().setString("history_file", options["history_file"].as<std::string>());
    if (options.count("verbose"))
        config().setBool("verbose", true);
    if (options.count("interactive"))
        config().setBool("interactive", true);
    if (options.count("pager"))
        config().setString("pager", options["pager"].as<std::string>());

    if (options.count("log-level"))
        Poco::Logger::root().setLevel(options["log-level"].as<std::string>());

    profile_events.print = options.count("print-profile-events");
    profile_events.delay_ms = options["profile-events-delay-ms"].as<UInt64>();

    processOptions(options_description, options, external_tables_arguments, hosts_and_ports_arguments);
    argsToConfig(common_arguments, config(), 100);
    clearPasswordFromCommandLine(argc, argv);

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

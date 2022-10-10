#include <stdlib.h>
#include <fcntl.h>
#include <map>
#include <iostream>
#include <iomanip>
#include <optional>
#include <base/scope_guard_safe.h>
#include <boost/program_options.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <filesystem>
#include <string>
#include "Client.h"

#include <base/find_symbols.h>

#include <Common/config_version.h>
#include <Common/Exception.h>
#include <Common/formatReadable.h>
#include <Common/TerminalSize.h>

#include <Client/TestHint.h>
#include <Poco/Util/Application.h>

#include <IO/ReadBufferFromString.h>
#include <IO/ReadHelpers.h>
#include <IO/WriteHelpers.h>
#include <IO/WriteBufferFromOStream.h>
#include <IO/UseSSL.h>

#include "TestTags.h"

#ifndef __clang__
#pragma GCC optimize("-fno-var-tracking-assignments")
#endif

namespace fs = std::filesystem;


namespace PYJU
{
namespace ErrorCodes
{
    extern const int BAD_ARGUMENTS;
    extern const int UNKNOWN_PACKET_FROM_SERVER;
    extern const int SYNTAX_ERROR;
    extern const int TOO_DEEP_RECURSION;
    extern const int NETWORK_ERROR;
    extern const int AUTHENTICATION_FAILED;
}

void Client::initialize(Poco::Util::Application & self)
{
    Poco::Util::Application::initialize(self);

    const char * home_path_cstr = getenv("HOME");
    if (home_path_cstr)
        home_path = home_path_cstr;
}


int Client::main(const std::vector<std::string> & /*args*/)
try
{
    UseSSL use_ssl;
    setupSignalHandler();

    std::cout << std::fixed << std::setprecision(3);
    std::cerr << std::fixed << std::setprecision(3);

    processConfig();

    /// Includes delayed_interactive.
    if (is_interactive)
    {
        clearTerminal();
        showClientVersion();
    }

    if (is_interactive && !delayed_interactive)
    {
        runInteractive();
    }
    else
    {
        runNonInteractive();

        // If exception code isn't zero, we should return non-zero return
        // code anyway.

        if (delayed_interactive)
            runInteractive();
    }

    return 0;
}
catch (const Exception & e)
{
    bool need_print_stack_trace = config().getBool("stacktrace", false) && e.code() != ErrorCodes::NETWORK_ERROR;
    std::cerr << getExceptionMessage(e, need_print_stack_trace, true) << std::endl << std::endl;
    /// If exception code isn't zero, we should return non-zero return code anyway.
    return e.code() ? e.code() : -1;
}
catch (...)
{
    std::cerr << getCurrentExceptionMessage(false) << std::endl;
    return getCurrentExceptionCode();
}

void Client::printHelpMessage(const OptionsDescription & options_description)
{
    std::cout << options_description.main_description.value() << "\n";
    std::cout << options_description.external_description.value() << "\n";
    std::cout << "In addition, --param_name=value can be specified for substitution of parameters for parametrized queries.\n";
}


void Client::addOptions(OptionsDescription & options_description)
{
    /// Main commandline options related to client functionality and all parameters from Settings.
    options_description.main_description->add_options()
        ("config,c", po::value<std::string>(), "config-file path (another shorthand)")
        ("secure,s", "Use TLS connection")
        ("user,u", po::value<std::string>()->default_value("default"), "user")
        /** If "--password [value]" is used but the value is omitted, the bad argument exception will be thrown.
            * implicit_value is used to avoid this exception (to allow user to type just "--password")
            * Since currently boost provides no way to check if a value has been set implicitly for an option,
            * the "\n" is used to distinguish this case because there is hardly a chance a user would use "\n"
            * as the password.
            */
        ("password", po::value<std::string>()->implicit_value("\n", ""), "password")
        ("ask-password", "ask-password")
        ("quota_key", po::value<std::string>(), "A string to differentiate quotas when the user have keyed quotas configured on server")
        ("testmode,T", "enable test hints in comments")

        ("max_client_network_bandwidth", po::value<int>(), "the maximum speed of data exchange over the network for the client in bytes per second.")
        ("compression", po::value<bool>(), "enable or disable compression")

        ("query-fuzzer-runs", po::value<int>()->default_value(0), "After executing every SELECT query, do random mutations in it and run again specified number of times. This is used for testing to discover unexpected corner cases.")
        ("interleave-queries-file", po::value<std::vector<std::string>>()->multitoken(),
            "file path with queries to execute before every file from 'queries-file'; multiple files can be specified (--queries-file file1 file2...); this is needed to enable more aggressive fuzzing of newly added tests (see 'query-fuzzer-runs' option)")

        ("opentelemetry-traceparent", po::value<std::string>(), "OpenTelemetry traceparent header as described by W3C Trace Context recommendation")
        ("opentelemetry-tracestate", po::value<std::string>(), "OpenTelemetry tracestate header as described by W3C Trace Context recommendation")

        ("no-warnings", "disable warnings when client connects to server")
    ;

    /// Commandline options related to external tables.

    options_description.external_description.emplace(createOptionsDescription("External tables options", terminal_width));
    options_description.external_description->add_options()
    (
        "file", po::value<std::string>(), "data file or - for stdin"
    )
    (
        "name", po::value<std::string>()->default_value("_data"), "name of the table"
    )
    (
        "format", po::value<std::string>()->default_value("TabSeparated"), "data format"
    )
    (
        "structure", po::value<std::string>(), "structure"
    )
    (
        "types", po::value<std::string>(), "types"
    );

    /// Commandline options related to hosts and ports.
    options_description.hosts_and_ports_description.emplace(createOptionsDescription("Hosts and ports options", terminal_width));
    options_description.hosts_and_ports_description->add_options()
        ("host,h", po::value<String>()->default_value("localhost"),
         "Server hostname. Multiple hosts can be passed via multiple arguments"
         "Example of usage: '--host host1 --host host2 --port port2 --host host3 ...'"
         "Each '--port port' will be attached to the last seen host that doesn't have a port yet,"
         "if there is no such host, the port will be attached to the next first host or to default host.")
         ("port", po::value<UInt16>(), "server ports")
    ;
}


void Client::processOptions(const OptionsDescription & options_description,
                            const CommandLineOptions & options,
                            const std::vector<Arguments> & external_tables_arguments,
                            const std::vector<Arguments> & hosts_and_ports_arguments)
{
    namespace po = boost::program_options;

    size_t number_of_external_tables_with_stdin_source = 0;
    for (size_t i = 0; i < external_tables_arguments.size(); ++i)
    {
        /// Parse commandline options related to external tables.
        po::parsed_options parsed_tables = po::command_line_parser(external_tables_arguments[i]).options(
            options_description.external_description.value()).run();
        po::variables_map external_options;
        po::store(parsed_tables, external_options);
    }

    if (options.count("config-file") && options.count("config"))
        throw Exception("Two or more configuration files referenced in arguments", ErrorCodes::BAD_ARGUMENTS);

    if (options.count("config"))
        config().setString("config-file", options["config"].as<std::string>());
    if (options.count("interleave-queries-file"))
        interleave_queries_files = options["interleave-queries-file"].as<std::vector<std::string>>();
    if (options.count("secure"))
        config().setBool("secure", true);
    if (options.count("user") && !options["user"].defaulted())
        config().setString("user", options["user"].as<std::string>());
    if (options.count("password"))
        config().setString("password", options["password"].as<std::string>());
    if (options.count("ask-password"))
        config().setBool("ask-password", true);
    if (options.count("quota_key"))
        config().setString("quota_key", options["quota_key"].as<std::string>());
    if (options.count("testmode"))
        config().setBool("testmode", true);
    if (options.count("compression"))
        config().setBool("compression", options["compression"].as<bool>());
    if (options.count("no-warnings"))
        config().setBool("no-warnings", true);
}


void Client::processConfig()
{
    /// Batch mode is enabled if one of the following is true:
    /// - -e (--query) command line option is present.
    ///   The value of the option is used as the text of query (or of multiple queries).
    ///   If stdin is not a terminal, INSERT data for the first query is read from it.
    /// - stdin is not a terminal. In this case queries are read from it.
    /// - -qf (--queries-file) command line option is present.
    ///   The value of the option is used as file with query (or of multiple queries) to execute.

    delayed_interactive = config().has("interactive") && (config().has("query") || config().has("queries-file"));
    if (stdin_is_a_tty
        && (delayed_interactive || (!config().has("query") && queries_files.empty())))
    {
        is_interactive = true;
    }
    else
    {
        echo_queries = config().getBool("echo", false);
        ignore_error = config().getBool("ignore-error", false);

    }
    print_stack_trace = config().getBool("stacktrace", false);


    // is_default_format = !config().has("vertical") && !config().has("format");
    // if (config().has("vertical"))
    //     format = config().getString("format", "Vertical");
    // else
    //     format = config().getString("format", is_interactive ? "PrettyCompact" : "TabSeparated");

}

}


#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

int mainPyJu(int argc, char ** argv)
{
    try
    {
        PYJU::Client client;
        client.init(argc, argv);
        return client.run();
    }
    catch (const PYJU::Exception & e)
    {
        std::cerr << PYJU::getExceptionMessage(e, false) << std::endl;
        return 1;
    }
    catch (const boost::program_options::error & e)
    {
        std::cerr << "Bad arguments: " << e.what() << std::endl;
        return PYJU::ErrorCodes::BAD_ARGUMENTS;
    }
    catch (...)
    {
        std::cerr << PYJU::getCurrentExceptionMessage(true) << std::endl;
        return 1;
    }
}

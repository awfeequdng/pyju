#pragma once

#include "Common/NamePrompter.h"
#include <Common/InterruptListener.h>
#include <Common/ShellCommand.h>
#include <Common/Stopwatch.h>
#include <Common/config.h>
#include <Poco/Util/Application.h>
#include <Client/Suggest.h>
#include <boost/program_options.hpp>
#include <Core/Names.h>

namespace po = boost::program_options;


namespace PYJU
{

namespace ErrorCodes
{
    extern const int NOT_IMPLEMENTED;
}

enum MultiQueryProcessingStage
{
    QUERIES_END,
    PARSING_EXCEPTION,
    CONTINUE_PARSING,
    EXECUTE_QUERY,
    PARSING_FAILED,
};

void interruptSignalHandler(int signum);

class ClientBase : public Poco::Util::Application, public IHints<2, ClientBase>
{

public:
    using Arguments = std::vector<String>;

    ClientBase();
    ~ClientBase() override;

    void init(int argc, char ** argv);

    std::vector<String> getAllRegisteredNames() const override { return cmd_options; }

protected:
    void runInteractive();
    void runNonInteractive();

    virtual String getName() const = 0;

    void processTextAsSingleQuery(const String & full_query);

    static void setupSignalHandler();

    static void clearTerminal();
    void showClientVersion();

    using ProgramOptionsDescription = boost::program_options::options_description;
    using CommandLineOptions = boost::program_options::variables_map;

    struct OptionsDescription
    {
        std::optional<ProgramOptionsDescription> main_description;
        std::optional<ProgramOptionsDescription> external_description;
        std::optional<ProgramOptionsDescription> hosts_and_ports_description;
    };

    virtual void printHelpMessage(const OptionsDescription & options_description) = 0;
    virtual void addOptions(OptionsDescription & options_description) = 0;
    virtual void processOptions(const OptionsDescription & options_description,
                                const CommandLineOptions & options,
                                const std::vector<Arguments> & external_tables_arguments,
                                const std::vector<Arguments> & hosts_and_ports_arguments) = 0;
    virtual void processConfig() = 0;

protected:
    bool processQueryText(const String & text);
    void initQueryIdFormats();

private:
    String prompt() const;

    void resetOutput();
    void outputQueryInfo(bool echo_query_);
    void readArguments(
        int argc,
        char ** argv,
        Arguments & common_arguments,
        std::vector<Arguments> & external_tables_arguments,
        std::vector<Arguments> & hosts_and_ports_arguments);
    void parseAndCheckOptions(OptionsDescription & options_description, po::variables_map & options, Arguments & arguments);

protected:

    bool is_interactive = false; /// Use either interactive line editing interface or batch mode.
    bool is_multiquery = false;
    bool delayed_interactive = false;

    bool echo_queries = false; /// Print queries before execution in batch mode.
    bool ignore_error = false; /// In case of errors, don't print error message, continue to next query. Only applicable for non-interactive mode.
    bool print_time_to_stderr = false; /// Output execution time to stderr in batch mode.

    std::optional<Suggest> suggest;
    bool load_suggestions = false;

    std::vector<String> queries_files; /// If not empty, queries will be read from these files
    std::vector<String> interleave_queries_files; /// If not empty, run queries from these files before processing every file from 'queries_files'.
    std::vector<String> cmd_options;

    bool stdin_is_a_tty = false; /// stdin is a terminal.
    bool stdout_is_a_tty = false; /// stdout is a terminal.
    uint64_t terminal_width = 0;

    bool has_vertical_output_suffix = false; /// Is \G present at the end of the query string?

    /// We will format query_id in interactive mode in various ways, the default is just to print Query id: ...
    std::vector<std::pair<String, String>> query_id_formats;
    String prompt_by_server_display_name;
    /// Buffer that reads from stdin in batch mode.
    ReadBufferFromFileDescriptor std_in{STDIN_FILENO};
    /// Console output.
    WriteBufferFromFileDescriptor std_out{STDOUT_FILENO};
    std::unique_ptr<ShellCommand> pager_cmd;

    String home_path;
    String history_file; /// Path to a file containing command history.

    String current_profile;

    bool print_stack_trace = false;
    /// Likewise, the last exception that occurred on the client.
    std::unique_ptr<Exception> client_exception;

    /// If the last query resulted in exception. `server_exception` or
    /// `client_exception` must be set.
    bool have_error = false;

    struct
    {
        bool print = false;
        /// UINT64_MAX -- print only last
        UInt64 delay_ms = 0;
        Stopwatch watch;
        /// For printing only last (delay_ms == 0).
    } profile_events;
};

}

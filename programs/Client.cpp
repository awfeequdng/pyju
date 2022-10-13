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
#include <iostream>
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

int pyju_main_script(std::string script_text);
int pyju_main(int argc, char **argv);
extern "C" void pyju_init();
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

int Client::main(const std::vector<std::string> & args)
try
{
    std::cout << "args: " << std::endl;
    for (auto arg: args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    UseSSL use_ssl;
    setupSignalHandler();
    pyju_init();    // 初始化pyju_vm

    std::cout << std::fixed << std::setprecision(3);
    std::cerr << std::fixed << std::setprecision(3);

    /// Includes delayed_interactive.
    if (is_interactive)
    {
        clearTerminal();
        showClientVersion();
    }

    std::cout << "is_interactive: " << is_interactive << std::endl;
    std::cout << "delayed_interactive: " << delayed_interactive << std::endl;
    if (is_interactive && !delayed_interactive)
    {
        runInteractive(pyju_main_script);
    }
    else
    {
        runNonInteractive(pyju_main);

        // If exception code isn't zero, we should return non-zero return
        // code anyway.


        if (delayed_interactive)
            runInteractive(pyju_main_script);
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
    std::cout << "In addition, --param_name=value can be specified for substitution of parameters for parametrized queries.\n";
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

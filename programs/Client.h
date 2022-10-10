#pragma once

#include <Client/ClientBase.h>


namespace PYJU
{

class Client : public ClientBase
{
public:
    Client() = default;

    void initialize(Poco::Util::Application & self) override;

    int main(const std::vector<String> & /*args*/) override;

protected:
    String getName() const override { return "client"; }

    void printHelpMessage(const OptionsDescription & options_description) override;
    void addOptions(OptionsDescription & options_description) override;
    void processOptions(
        const OptionsDescription & options_description,
        const CommandLineOptions & options,
        const std::vector<Arguments> & external_tables_arguments,
        const std::vector<Arguments> & hosts_and_ports_arguments) override;
    void processConfig() override;

private:
    void printChangedSettings() const;
    std::vector<String> loadWarningMessages();
};
}

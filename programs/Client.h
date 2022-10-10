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

private:
    void printChangedSettings() const;
    std::vector<String> loadWarningMessages();
};
}

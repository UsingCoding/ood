#include <iostream>
#include <Strings.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/InputDefinition/InputDefinition.hpp>
#include "Application.hpp"
#include "../CommandHandler/SetTitleCommandHandler/SetTitleCommandHandler.hpp"
#include "../CommandHandler/ListCommandHandler/ListCommandHandler.hpp"

using namespace Common::Console;

void Application::Configure(std::unique_ptr<IInputDefinition> &definition)
{
    RegisterCommandHandlers();
}

void Application::DoRun(IInput &input, IOutput &output)
{
    *output << "Run" << std::endl;

    std::string userInput;

    while (getline(std::cin, userInput))
    {
        auto arguments = std::make_unique<std::vector<std::string>>(Strings::Split(userInput, " "));

        if (arguments->size() == 0)
        {
            *output << "You must provide more than one argument" << std::endl;
            continue;
        }

        try
        {
            auto & commandHandler = m_commandHandlerRegistry->GetHandler((*arguments)[0]);

            arguments->erase(arguments->begin());

            std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

            commandHandler->ConfigureInputDefinition(definition);

            ArgvInput argvInput(std::move(arguments));

            argvInput.Bind(std::move(definition));

            argvInput.Validate();

            commandHandler->Handle(argvInput, output);
        }
        catch (std::logic_error e)
        {
            *output << e.what() << std::endl;
        }
        catch (std::runtime_error e)
        {
            *output << e.what() << std::endl;
        }
    }
}

void Application::RegisterCommandHandlers()
{
    m_commandHandlerRegistry->RegisterHandler("SetTitle", std::make_unique<SetTitleCommandHandler>(m_commandsHistory, m_document));
    m_commandHandlerRegistry->RegisterHandler("List", std::make_unique<ListCommandHandler>(m_commandsHistory, m_document));
}

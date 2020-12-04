#include <iostream>
#include <Strings.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/InputDefinition/InputDefinition.hpp>
#include "Application.hpp"
#include "../Controller/SetTitleController/SetTitleController.hpp"
#include "../ControllerRegistry/Exception/ItemNotFoundInRegistryException.hpp"

const std::string Application::EXIT_COMMAND = "Exit";

using namespace Common::Console;

void Application::Configure(std::unique_ptr<IInputDefinition> &definition)
{
    definition->AddOption(InputOption("repo_dir", 'd', InputOption::ValueMode::VALUE_OPTIONAL));
}

void Application::DoRun(IInput &input, IOutput &output)
{
    auto newRepoPath = input.GetOption("repo_dir");

    if (newRepoPath.has_value())
    {
        m_fileResourceRepository->SetPath(newRepoPath.value());
    }

    m_fileResourceRepository->Init();

    *output << "Run" << std::endl;

    std::string userInput;

    while (getline(*input, userInput))
    {
        auto arguments = std::make_unique<std::vector<std::string>>(Strings::Split(userInput, " "));

        if (arguments->size() == 0)
        {
            *output << "You must provide more than zero arguments" << std::endl;
            continue;
        }

        if (arguments->size() == 1 && arguments->front() == EXIT_COMMAND)
        {
            *output << "Exit" << std::endl;
            break;
        }

        try
        {
            if (!m_controllerCommandsHolder->Has((*arguments)[0]))
            {
                *output << "Unknown command" << std::endl;
                continue;
            }

            auto controllerType = m_controllerCommandsHolder->Get(((*arguments)[0]));

            arguments->erase(arguments->begin());

            auto & controller = m_controllerRegistry->Get(controllerType);

            std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

            controller->ConfigureInputDefinition(definition);

            ArgvInput argvInput(std::move(arguments), *input);

            argvInput.Bind(std::move(definition));

            argvInput.Validate();

            controller->Handle(argvInput, output);

            *output << "Command executed successfully" << std::endl;
        }
        catch (const std::exception & e)
        {
            *output << e.what() << std::endl;
        }
    }

    m_fileResourceRepository->Clear();
}

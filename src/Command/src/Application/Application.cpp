#include <iostream>
#include <Strings.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/InputDefinition/InputDefinition.hpp>
#include "Application.hpp"
#include "../Controller/SetTitleController/SetTitleController.hpp"
#include "../ControllerRegistry/Exception/ItemNotFoundInRegistryException.hpp"

const std::map<std::string, ControllerType> Application::COMMAND_CONTROLLER_MAP = {
        std::make_pair("SetTitle", ControllerType::SET_TITLE),
        std::make_pair("List", ControllerType::LIST),
        std::make_pair("InsertParagraph", ControllerType::INSERT_PARAGRAPH),
        std::make_pair("ReplaceText", ControllerType::REPLACE_TEXT),
        std::make_pair("Undo", ControllerType::UNDO),
        std::make_pair("Redo", ControllerType::REDO),
        std::make_pair("InsertImage", ControllerType::INSERT_IMAGE),
        std::make_pair("ResizeImage", ControllerType::RESIZE_IMAGE),
        std::make_pair("Save", ControllerType::SAVE_DOCUMENT),
};

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

    *output << "Run" << std::endl;

    std::string userInput;

    while (getline(std::cin, userInput))
    {
        auto arguments = std::make_unique<std::vector<std::string>>(Strings::Split(userInput, " "));

        if (arguments->size() == 0)
        {
            *output << "You must provide more than zero arguments" << std::endl;
            continue;
        }

        try
        {
            auto it = COMMAND_CONTROLLER_MAP.find((*arguments)[0]);

            if (it == COMMAND_CONTROLLER_MAP.end())
            {
                *output << "Unknown command" << std::endl;
                continue;
            }

            arguments->erase(arguments->begin());

            auto & controller = m_controllerRegistry->Get(it->second);

            std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

            controller->ConfigureInputDefinition(definition);

            ArgvInput argvInput(std::move(arguments));

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
}

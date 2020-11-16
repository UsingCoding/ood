#include <iostream>
#include <Strings.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/InputDefinition/InputDefinition.hpp>
#include "Application.hpp"
#include "../Controller/SetTitleController/SetTitleController.hpp"
#include "../Controller/ListController/ListController.hpp"
#include "../Controller/InsertParagraphController/InsertParagraphController.hpp"
#include "../ControllerRegistry/Exception/ItemNotFoundInRegistryException.hpp"
#include "../Controller/ReplaceTextController/ReplaceTextController.hpp"
#include "../Controller/UndoController/UndoController.hpp"
#include "../Controller/RedoController/RedoController.hpp"
#include "../Controller/InsertImageController/InsertImageController.hpp"
#include "../Controller/ResizeImageController/ResizeImageController.hpp"
#include "../Controller/SaveDocumentController/SaveDocumentController.hpp"

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
            *output << "You must provide more than zero arguments" << std::endl;
            continue;
        }

        try
        {
            auto & controller = m_controllerRegistry->Get((*arguments)[0]);

            arguments->erase(arguments->begin());

            std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

            controller->ConfigureInputDefinition(definition);

            ArgvInput argvInput(std::move(arguments));

            argvInput.Bind(std::move(definition));

            argvInput.Validate();

            controller->Handle(argvInput, output);

            *output << "Command executed successfully" << std::endl;
        }
        catch (const ItemNotFoundInRegistryException & e)
        {
            *output << "Unknown command" << std::endl;
        }
        catch (const std::exception & e)
        {
            *output << e.what() << std::endl;
        }
    }
}

void Application::RegisterCommandHandlers()
{
    m_controllerRegistry->Register("SetTitle", std::make_unique<SetTitleController>(m_commandsHistory, m_document));
    m_controllerRegistry->Register("List", std::make_unique<ListController>(m_commandsHistory, m_document));
    m_controllerRegistry->Register("InsertParagraph",std::make_unique<InsertParagraphController>(m_commandsHistory, m_document));
    m_controllerRegistry->Register("ReplaceText",std::make_unique<ReplaceTextController>(m_commandsHistory, m_document));
    m_controllerRegistry->Register("Undo",std::make_unique<UndoController>(m_document));
    m_controllerRegistry->Register("Redo",std::make_unique<RedoController>(m_document));
    m_controllerRegistry->Register("InsertImage",std::make_unique<InsertImageController>(m_commandsHistory, m_document, m_fileResourceRepository));
    m_controllerRegistry->Register("ResizeImage",std::make_unique<ResizeImageController>(m_commandsHistory, m_document));
    m_controllerRegistry->Register("Save",std::make_unique<SaveDocumentController>(m_commandsHistory, m_document));
}

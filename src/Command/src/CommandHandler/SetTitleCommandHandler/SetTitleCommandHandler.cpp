#include <Strings.hpp>
#include "SetTitleCommandHandler.hpp"
#include "../../Command/SetTitleCommand/SetTitleCommand.hpp"

void SetTitleCommandHandler::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("title"));
}

void SetTitleCommandHandler::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    auto newTitle = input.GetArgument("title");

    auto command = std::make_unique<SetTitleCommand>(newTitle.value(), m_document->GetTitle());

    command->Execute(*m_document);

    AddToCommandHistory(std::move(command));
}

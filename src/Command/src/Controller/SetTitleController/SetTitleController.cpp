#include <Strings.hpp>
#include "SetTitleController.hpp"
#include "../../Command/SetTitleCommand/SetTitleCommand.hpp"

void SetTitleController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("title"));
}

void SetTitleController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    auto newTitle = input.GetArgument("title");

    auto command = std::make_unique<SetTitleCommand>(newTitle.value(), m_document->GetTitle());

    AddToCommandHistory(std::move(command));
}

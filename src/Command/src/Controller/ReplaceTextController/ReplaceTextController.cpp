#include "ReplaceTextController.hpp"
#include "../../Command/ReplaceTextCommand/ReplaceTextCommand.hpp"

void ReplaceTextController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("position"));
    definition->AddArgument(Common::Console::InputArgument("text"));
}

void ReplaceTextController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    std::optional<size_t> position;
    const auto arg = input.GetArgument("position").value();

    try
    {
        position = std::stoi(arg);
    }
    catch (std::exception & e)
    {
        throw std::logic_error("Invalid argument provided for position");
    }

    auto documentItem = m_document->GetItem(position.value_or(m_document->GetItemsCount() - 1));

    if (documentItem.GetImage() != nullptr && documentItem.GetParagraph() == nullptr)
    {
        throw std::logic_error("You cannot replace text on item with type non paragraph");
    }

    auto command = std::make_unique<ReplaceTextCommand>(documentItem.GetParagraph(), input.GetArgument("text").value());

    command->Execute(*m_document);

    AddToCommandHistory(std::move(command));
}

#include "DeleteItemController.hpp"
#include "../../Command/DeleteItemCommand/DeleteItemCommand.hpp"

void DeleteItemController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("position"));
}

void DeleteItemController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    size_t position;
    const auto arg = input.GetArgument("position").value();

    try
    {
        position = std::stoi(arg);
    }
    catch (std::exception & e)
    {
        *output << "Invalid argument provided for position" << std::endl;
        return;
    }

    if (m_document->GetItemsCount() < position)
    {
        *output << "Can`t delete not existing item" << std::endl;
        return;
    }

    auto command = std::make_unique<DeleteItemCommand>(m_document->GetItem(position), position);

    AddToCommandHistory(std::move(command));
}

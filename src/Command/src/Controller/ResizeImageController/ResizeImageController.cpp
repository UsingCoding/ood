#include "ResizeImageController.hpp"
#include "../../Command/ResizeImageCommand/ResizeImageCommand.hpp"

void ResizeImageController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("position"));
    definition->AddArgument(Common::Console::InputArgument("width"));
    definition->AddArgument(Common::Console::InputArgument("height"));
}

void ResizeImageController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    std::optional<size_t> position;
    const auto arg = input.GetArgument("position").value();

    try
    {
        position = std::stoi(arg);
    }
    catch (std::exception & e)
    {
        throw std::logic_error("Invalid value for position");
    }

    int width;
    int height;

    try
    {
        auto widthStr = input.GetArgument("width").value();
        auto heightStr = input.GetArgument("height").value();
        width = std::stoi(widthStr);
        height = std::stoi(heightStr);
    }
    catch (const std::exception & e)
    {
        throw std::logic_error("Invalid width or height");
    }

    auto documentItem = m_document->GetItem(position.value());

    if (documentItem.GetImage() == nullptr && documentItem.GetParagraph() != nullptr)
    {
        throw std::logic_error("You cannot resize item with type non image");
    }

    auto command = std::make_unique<ResizeImageCommand>(
            documentItem.GetImage(),
            width,
            height
    );

    AddToCommandHistory(std::move(command));
}

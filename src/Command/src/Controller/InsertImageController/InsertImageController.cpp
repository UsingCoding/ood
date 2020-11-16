#include "InsertImageController.hpp"
#include "../../Command/InsertImageCommand/InsertImageCommand.hpp"

void InsertImageController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("position"));
    definition->AddArgument(Common::Console::InputArgument("width"));
    definition->AddArgument(Common::Console::InputArgument("height"));
    definition->AddArgument(Common::Console::InputArgument("path"));
}

void InsertImageController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    std::optional<size_t> position;
    const auto arg = input.GetArgument("position").value();

    try
    {
        position = std::stoi(arg);
    }
    catch (std::exception & e)
    {
        if (arg != "end")
        {
            throw std::logic_error("Invalid argument provided for position");
        }

        position = std::nullopt;
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
    catch (std::exception & e)
    {
        throw std::logic_error("Invalid width or height");
    }

    auto path = IDocument::Path(input.GetArgument("path").value());

    auto file = std::make_shared<FileResource>(path);

    m_fileResourceRepo->Add(file);

    auto command = std::make_unique<InsertImageCommand>(
        file,
        m_fileResourceRepo,
        path,
        width,
        height,
        position
    );
    
    AddToCommandHistory(std::move(command));
}

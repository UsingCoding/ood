#include <iostream>
#include "InsertParagraphController.hpp"
#include "../../Command/InsertParagraphCommand/InsertParagraphCommand.hpp"

void InsertParagraphController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddArgument(Common::Console::InputArgument("position"));
    definition->AddArgument(Common::Console::InputArgument(
            "text",
            Common::Console::InputArgument::Mode::REQUIRED,
            Common::Console::InputArgument::ValueMode::TEXT
    ));
}

void InsertParagraphController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
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

    auto command = std::make_unique<InsertParagraphCommand>(position, input.GetArgument("text").value());

    AddToCommandHistory(std::move(command));
}

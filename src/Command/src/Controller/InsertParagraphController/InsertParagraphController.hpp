#pragma once

#include "../AbstractController/AbstractController.hpp"

class InsertParagraphController : public AbstractController
{
public:
    InsertParagraphController(
        std::unique_ptr<ICommandsHistory> &commandsHistory,
        std::unique_ptr<IDocument> &document)
    : AbstractController(commandsHistory, document) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;
};

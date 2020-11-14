#pragma once

#include "../AbstractCommandHandler/AbstractCommandHandler.hpp"

class ListCommandHandler : public AbstractCommandHandler
{
public:
    ListCommandHandler(
        std::unique_ptr<ICommandsHistory> &commandsHistory,
        std::unique_ptr<IDocument> &document
    )
    : AbstractCommandHandler(commandsHistory, document) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;
};

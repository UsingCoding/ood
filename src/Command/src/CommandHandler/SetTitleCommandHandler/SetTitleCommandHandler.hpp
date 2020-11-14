#pragma once

#include "../ICommandHandler.hpp"
#include "../AbstractCommandHandler/AbstractCommandHandler.hpp"

class SetTitleCommandHandler : public AbstractCommandHandler
{
public:
    SetTitleCommandHandler(
            std::unique_ptr<ICommandsHistory> &commandsHistory,
            std::unique_ptr<IDocument> &document)
    : AbstractCommandHandler(commandsHistory, document) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;
};

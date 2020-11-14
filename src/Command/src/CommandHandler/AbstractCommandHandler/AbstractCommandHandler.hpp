#pragma once

#include <memory>
#include "../ICommandHandler.hpp"
#include "../../History/ICommandsHistory.hpp"

class AbstractCommandHandler : public ICommandHandler
{
public:
    AbstractCommandHandler(
        std::unique_ptr<ICommandsHistory> &commandsHistory,
        std::unique_ptr<IDocument> &document
    )
    : m_commandsHistory(commandsHistory), m_document(document) {}

protected:
    void AddToCommandHistory(std::unique_ptr<ICommand> command);

    std::unique_ptr<ICommandsHistory> & m_commandsHistory;
    std::unique_ptr<IDocument> & m_document;
};

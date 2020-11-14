#pragma once

#include <memory>
#include "../IController.hpp"
#include "../../History/ICommandsHistory.hpp"

class AbstractController : public IController
{
public:
    AbstractController(
        std::shared_ptr<ICommandsHistory> &commandsHistory,
        std::unique_ptr<IDocument> &document
    )
    : m_commandsHistory(commandsHistory), m_document(document) {}

protected:
    void AddToCommandHistory(std::unique_ptr<ICommand> command);

    std::shared_ptr<ICommandsHistory> & m_commandsHistory;
    std::unique_ptr<IDocument> & m_document;
};

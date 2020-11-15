#include "AbstractController.hpp"

void AbstractController::AddToCommandHistory(std::unique_ptr<ICommand> command)
{
    m_commandsHistory->AddAndExecuteCommand(std::move(command), *m_document);
}

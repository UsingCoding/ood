#include "AbstractController.hpp"

void AbstractController::AddToCommandHistory(std::unique_ptr<ICommand> command)
{
    m_commandsHistory->AddCommand(std::move(command));
}

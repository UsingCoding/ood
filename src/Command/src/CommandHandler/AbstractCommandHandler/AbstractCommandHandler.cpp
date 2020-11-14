#include "AbstractCommandHandler.hpp"

void AbstractCommandHandler::AddToCommandHistory(std::unique_ptr<ICommand> command)
{
    m_commandsHistory->AddCommand(std::move(command));
}

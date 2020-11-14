#include "CommandsHistory.hpp"

void CommandsHistory::AddCommand(std::unique_ptr<ICommand> command)
{
    m_commands.push_back(std::move(command));
}

std::unique_ptr<ICommand> CommandsHistory::PopCommand()
{
    auto command = std::move(m_commands.back());

    m_commands.pop_back();

    return std::move(command);
}

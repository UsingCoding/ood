#pragma once

#include "ICommandsHistory.hpp"

class CommandsHistory : public ICommandsHistory
{
public:
    void AddCommand(std::unique_ptr<ICommand> command) override;

    std::unique_ptr<ICommand> PopCommand() override;

private:
    std::vector<std::unique_ptr<ICommand>> m_commands;
};

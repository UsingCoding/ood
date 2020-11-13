#pragma once

#include "../Command/ICommand.hpp"

class ICommandsHistory
{
public:
    virtual void AddCommand(std::unique_ptr<ICommand> & command) = 0;
    virtual std::unique_ptr<ICommand> PopCommand() = 0;

    virtual ~ICommandsHistory() = default;
};

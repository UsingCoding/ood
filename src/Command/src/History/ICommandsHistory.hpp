#pragma once

#include "../Command/ICommand.hpp"

class ICommandsHistory
{
public:
    virtual void AddCommand(std::unique_ptr<ICommand> command) = 0;
    virtual std::unique_ptr<ICommand> PopCommand() = 0;
    virtual void Undo(IDocument & document) = 0;
    virtual void Redo(IDocument & document) = 0;
    virtual bool IsEmpty() = 0;
    virtual bool AtTop() = 0;

    virtual ~ICommandsHistory() = default;
};

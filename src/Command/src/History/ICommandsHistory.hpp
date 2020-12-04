#pragma once

#include "../Command/ICommand.hpp"

class ICommandsHistory
{
public:
    virtual void AddAndExecuteCommand(std::unique_ptr<ICommand> command, IDocument & document) = 0;
    virtual void Undo(IDocument & document) = 0;
    virtual void Redo(IDocument & document) = 0;
    virtual bool IsEmpty() = 0;
    virtual bool AtTop() = 0;
    virtual bool AtBottom() = 0;

    virtual ~ICommandsHistory() = default;
};

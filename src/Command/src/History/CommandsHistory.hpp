#pragma once

#include "ICommandsHistory.hpp"

class CommandsHistory : public ICommandsHistory
{
public:
    CommandsHistory();

    void AddAndExecuteCommand(std::unique_ptr<ICommand> command, IDocument & document) override;

    void Undo(IDocument &document) override;

    void Redo(IDocument &document) override;

    bool IsEmpty() override;

    bool AtTop() override;

    bool AtBottom() override;

private:
    std::vector<std::unique_ptr<ICommand>> m_commands;
    size_t m_topPtr = 0;
    const static size_t CAPACITY = 10;
};

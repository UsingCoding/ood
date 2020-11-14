#pragma once

#include "ICommandsHistory.hpp"

class CommandsHistory : public ICommandsHistory
{
public:
    void AddCommand(std::unique_ptr<ICommand> command) override;

    std::unique_ptr<ICommand> PopCommand() override;

    void Undo(IDocument &document) override;

    void Redo(IDocument &document) override;

    bool IsEmpty() override;

    bool AtTop() override;

private:
    std::vector<std::unique_ptr<ICommand>> m_commands;
    size_t m_topPtr;
    const static size_t MAX_COMMAND_HISTORY_CAPACITY = 10;
};

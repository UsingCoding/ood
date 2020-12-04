#include "CommandsHistory.hpp"

CommandsHistory::CommandsHistory()
{
    m_commands.reserve(CAPACITY + 1);
}

void CommandsHistory::AddAndExecuteCommand(std::unique_ptr<ICommand> command, IDocument & document)
{
    if (!AtTop() && m_commands.size() != 0)
    {
        for (int i = m_commands.size() - 1; i >= m_topPtr; --i)
        {
            m_commands[i]->Dispose();

            m_commands.erase(m_commands.begin() + i);
        }
    }

    command->Execute(document);

    m_commands.push_back(std::move(command));

    if (m_topPtr != CAPACITY)
    {
        m_topPtr++;
    }

    if (m_commands.size() > CAPACITY)
    {
        m_commands.erase(m_commands.begin());
    }
}

void CommandsHistory::Undo(IDocument &document)
{
    if (IsEmpty())
    {
        throw std::runtime_error("Can`t undo with empty command stack");
    }

    if (AtBottom())
    {
        throw std::runtime_error("Can`t undo, already at history bottom");
    }

    m_commands.at(m_topPtr - 1)->Revert(document);
    m_topPtr--;
}

void CommandsHistory::Redo(IDocument &document)
{
    if (AtTop())
    {
        throw std::runtime_error("Can`t redo, already at history top");
    }

    m_commands.at(m_topPtr)->Execute(document);
    m_topPtr++;
}

bool CommandsHistory::IsEmpty()
{
    return m_commands.size() == 0;
}

bool CommandsHistory::AtTop()
{
    return m_topPtr == m_commands.size();
}

bool CommandsHistory::AtBottom()
{
    return m_topPtr == 0;
}



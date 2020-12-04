#include "MockCommand.hpp"

void CommandHistoryTests::MockCommand::Execute(IDocument &document)
{
    m_callStack.push_back(m_id);
}

void CommandHistoryTests::MockCommand::Revert(IDocument &document)
{
    m_callStack.pop_back();
}

void CommandHistoryTests::MockCommand::Dispose()
{
    m_disposeStack.push_back(m_id);
}

#include "SetTitleCommand.hpp"

SetTitleCommand::SetTitleCommand(
        const std::string & newTitle,
        const std::string &oldTitle
)
: m_newTitle(newTitle), m_oldTitle(oldTitle)
{}

void SetTitleCommand::Execute(IDocument &document)
{
    document.SetTitle(m_newTitle);
}

void SetTitleCommand::Revert(IDocument &document)
{
    document.SetTitle(m_oldTitle);
}

void SetTitleCommand::Dispose()
{

}

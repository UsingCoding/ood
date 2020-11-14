#include "ReplaceTextCommand.hpp"

ReplaceTextCommand::ReplaceTextCommand(
    const std::shared_ptr<IParagraph> &paragraph,
    const std::string &newText
)
: m_paragraph(paragraph), m_newText(newText), m_oldText(paragraph->GetText())
{}

void ReplaceTextCommand::Execute(IDocument &document)
{
    m_paragraph->SetText(m_newText);
}

void ReplaceTextCommand::Revert(IDocument &document)
{
    m_paragraph->SetText(m_oldText);
}

void ReplaceTextCommand::Dispose()
{

}

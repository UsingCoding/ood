#include "InsertParagraphCommand.hpp"

void InsertParagraphCommand::Execute(IDocument &document)
{
    m_paragraph = document.InsertParagraph(m_text, m_position);
}

void InsertParagraphCommand::Revert(IDocument &document)
{
    document.DeleteItem(m_position.value_or(document.GetItemsCount() - 1));
    m_paragraph.reset();
}

void InsertParagraphCommand::Dispose()
{

}

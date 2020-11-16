#include "InsertImageCommand.hpp"

void InsertImageCommand::Execute(IDocument &document)
{
    m_image = document.InsertImage(m_originalPath, m_width, m_height, m_position);
}

void InsertImageCommand::Revert(IDocument &document)
{
    document.DeleteItem(m_position.value_or(document.GetItemsCount() - 1));
    m_image.reset();
}

void InsertImageCommand::Dispose()
{
    m_fileResourceRepo->Delete(m_file);
}

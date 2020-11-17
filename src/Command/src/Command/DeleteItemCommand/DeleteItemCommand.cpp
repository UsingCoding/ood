#include "DeleteItemCommand.hpp"

DeleteItemCommand::DeleteItemCommand(const DocumentItem &item, size_t position) : m_item(item), m_position(position) {}

void DeleteItemCommand::Execute(IDocument &document)
{
    document.DeleteItem(m_position);
}

void DeleteItemCommand::Revert(IDocument &document)
{
    if (m_item.GetImage() != nullptr)
    {
        document.InsertImage(
            m_item.GetImage()->GetPath(),
            m_item.GetImage()->GetWidth(),
            m_item.GetImage()->GetHeight(),
            m_position
        );
    }
    else if (m_item.GetParagraph() != nullptr)
    {
        document.InsertParagraph(
            m_item.GetParagraph()->GetText(),
            m_position
        );
    }
    else
    {
        throw std::runtime_error("Trying to return element with unknown type");
    }
}

void DeleteItemCommand::Dispose()
{

}

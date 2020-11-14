#include "Document.hpp"
#include "Elements/Paragraph/Paragraph.hpp"
#include "Elements/Image/Image.hpp"

Document::Document(std::unique_ptr<ICommandsHistory> & commandsHistory) : m_commandsHistory(commandsHistory)
{
    m_topPointer = 0;
}

std::shared_ptr<IParagraph> Document::InsertParagraph(const std::string &text, std::optional<size_t> position)
{
    auto paragraph = std::make_shared<Paragraph>(text);

    auto documentItem = DocumentItem(nullptr, paragraph);

    if (position != std::nullopt)
    {
        if (position.value() > m_items.size())
        {
            throw std::runtime_error("Trying to insert paragraph in position after all elements");
        }

        m_items.insert(m_items.begin() + position.value(), documentItem);
    }
    else
    {
        m_items.push_back(documentItem);
    }

    return paragraph;
}

std::shared_ptr<IImage> Document::InsertImage(const IDocument::Path &path, int width, int height, std::optional<size_t> position)
{
    auto image = std::make_shared<Image>(path, width, height);

    auto documentItem = DocumentItem(image, nullptr);

    m_items.push_back(documentItem);

    return image;
}

size_t Document::GetItemsCount() const
{
    return m_items.size();
}

ConstDocumentItem Document::GetItem(size_t index) const
{
    if (index >= m_items.size())
    {
        throw std::logic_error("Requested item by index more than count of items");
    }

    return m_items[index];
}

DocumentItem Document::GetItem(size_t index)
{
    if (index >= m_items.size())
    {
        throw std::logic_error("Requested item by index more than count of items");
    }

    return m_items[index];
}

void Document::DeleteItem(size_t index)
{
    if (index >= m_items.size())
    {
        throw std::logic_error("Requested to delete item by index more than count of items");
    }

    m_items.erase(m_items.begin() + index);
}

std::string Document::GetTitle() const
{
    return m_title;
}

void Document::SetTitle(const std::string &title)
{
    m_title = title;
}

bool Document::CanUndo() const
{
    return m_items.size() != 0;
}

void Document::Undo()
{

}

bool Document::CanRedo() const
{
    return m_topPointer != m_items.size() - 1;
}

void Document::Redo()
{

}

void Document::Save(const IDocument::Path &path) const
{

}
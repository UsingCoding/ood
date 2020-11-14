#include "Document.hpp"
#include "Elements/Paragraph/Paragraph.hpp"
#include "Elements/Image/Image.hpp"

std::shared_ptr<IParagraph> Document::InsertParagraph(const std::string &text, std::optional<size_t> position)
{
    auto paragraph = std::make_shared<Paragraph>(text);

    auto documentItem = DocumentItem(nullptr, paragraph);

    m_items.push_back(documentItem);

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
        throw std::logic_error("Requested item from index ore than count of items");
    }

    return m_items[index];
}

DocumentItem Document::GetItem(size_t index)
{
    if (index >= m_items.size())
    {
        throw std::logic_error("Requested item from index ore than count of items");
    }

    return m_items[index];
}

void Document::DeleteItem(size_t index)
{

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
    return false;
}

void Document::Undo()
{

}

bool Document::CanRedo() const
{
    return false;
}

void Document::Redo()
{

}

void Document::Save(const IDocument::Path &path) const
{

}

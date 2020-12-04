#include <fstream>
#include <algorithm>
#include <FileSystem.hpp>
#include "Document.hpp"
#include "Elements/Paragraph/Paragraph.hpp"
#include "Elements/Image/Image.hpp"

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
    return !m_commandsHistory->IsEmpty() && !m_commandsHistory->AtBottom();
}

void Document::Undo()
{
    m_commandsHistory->Undo(*this);
}

bool Document::CanRedo() const
{
    return !m_commandsHistory->AtTop();
}

void Document::Redo()
{
    m_commandsHistory->Redo(*this);
}

void Document::Save(const IDocument::Path &path) const
{
    FileSystem::CreateDirIfNotExists(path.parent_path() / "images");

    std::ofstream fout(path);

    if (!fout.is_open())
    {
        throw std::runtime_error("Failed to open file to save doc");
    }

    fout << m_converter->Convert(*this, m_pathPreparer);

    FileSystem::CreateDirIfNotExists(path.parent_path() / "images");

    std::for_each(m_items.begin(), m_items.end(), [&](const ConstDocumentItem & item){
        if (item.GetImage() == nullptr)
        {
            return;
        }

        auto imagePath = item.GetImage()->GetPath();
        std::experimental::filesystem::copy(imagePath, path.parent_path() / m_pathPreparer->Prepare(imagePath));
    });
}

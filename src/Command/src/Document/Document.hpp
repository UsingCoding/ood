#pragma once

#include "IDocument.hpp"
#include "../History/ICommandsHistory.hpp"
#include "DocumentConverter/IDocumentConverter.hpp"

class Document : public IDocument
{
public:
    Document(
        std::shared_ptr<ICommandsHistory> commandsHistory,
        std::unique_ptr<IDocumentConverter> converter,
        std::unique_ptr<IAssetPathPreparer> pathPreparer
    )
    :
    m_commandsHistory(commandsHistory),
    m_converter(std::move(converter)),
    m_pathPreparer(std::move(pathPreparer))
    {}

    std::shared_ptr<IParagraph> InsertParagraph(const std::string &text, std::optional<size_t> position) override;

    std::shared_ptr<IImage>
    InsertImage(const Path &path, int width, int height, std::optional<size_t> position) override;

    size_t GetItemsCount() const override;

    ConstDocumentItem GetItem(size_t index) const override;

    DocumentItem GetItem(size_t index) override;

    void DeleteItem(size_t index) override;

    std::string GetTitle() const override;

    void SetTitle(const std::string &title) override;

    bool CanUndo() const override;

    void Undo() override;

    bool CanRedo() const override;

    void Redo() override;

    void Save(const Path &path) const override;

private:
    std::vector<DocumentItem> m_items;
    std::string m_title;

    std::shared_ptr<ICommandsHistory> m_commandsHistory;
    std::unique_ptr<IDocumentConverter> m_converter;
    std::unique_ptr<IAssetPathPreparer> m_pathPreparer;
};

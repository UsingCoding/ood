#pragma once

#include <experimental/filesystem>
#include <optional>
#include "Elements/Paragraph/IParagraph.hpp"
#include "Elements/Image/IImage.hpp"
#include "Items/ConstDocumentItem/ConstDocumentItem.hpp"
#include "Items/DocumentItem/DocumentItem.hpp"

class IDocument
{
    typedef std::experimental::filesystem::path Path;

    virtual std::shared_ptr<IParagraph> InsertParagraph(
            const std::string & text,
            std::optional<size_t> position = std::nullopt) = 0;

    virtual std::shared_ptr<IImage> InsertImage(
            const Path & path,
            int width,
            int height,
            std::optional<size_t> position = std::nullopt) = 0;

    // Возвращает количество элементов в документе
    virtual size_t GetItemsCount() const = 0;

    // Доступ к элементам изображения
    virtual ConstDocumentItem GetItem(size_t index) const = 0;
    virtual DocumentItem GetItem(size_t index) = 0;

    // Удаляет элемент из документа
    virtual void DeleteItem(size_t index) = 0;

    // Возвращает заголовок документа
    virtual std::string GetTitle() const = 0;
    // Изменяет заголовок документа
    virtual void SetTitle(const std::string & title) = 0;

    // Сообщает о доступности операции Undo
    virtual bool CanUndo() const = 0;
    // Отменяет команду редактирования
    virtual void Undo() = 0;

    // Сообщает о доступности операции Redo
    virtual bool CanRedo() const = 0;
    // Выполняет отмененную команду редактирования
    virtual void Redo() = 0;

    virtual void Save(const Path & path) const = 0;

    virtual ~IDocument() = default;
};

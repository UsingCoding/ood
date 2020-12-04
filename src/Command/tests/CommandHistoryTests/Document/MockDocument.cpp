#include "MockDocument.hpp"

std::shared_ptr<IParagraph>
CommandHistoryTests::MockDocument::InsertParagraph(const std::string &text, std::optional<size_t> position)
{
    return std::shared_ptr<IParagraph>();
}

std::shared_ptr<IImage>
CommandHistoryTests::MockDocument::InsertImage(const IDocument::Path &path, int width, int height, std::optional<size_t> position)
{
    return std::shared_ptr<IImage>();
}

size_t CommandHistoryTests::MockDocument::GetItemsCount() const
{
    return 0;
}

ConstDocumentItem CommandHistoryTests::MockDocument::GetItem(size_t index) const
{
    return ConstDocumentItem(nullptr, nullptr);
}

DocumentItem CommandHistoryTests::MockDocument::GetItem(size_t index)
{
    return DocumentItem(nullptr, nullptr);
}

void CommandHistoryTests::MockDocument::DeleteItem(size_t index)
{

}

std::string CommandHistoryTests::MockDocument::GetTitle() const
{
    return std::__cxx11::string();
}

void CommandHistoryTests::MockDocument::SetTitle(const std::string &title)
{

}

bool CommandHistoryTests::MockDocument::CanUndo() const {
    return false;
}

void CommandHistoryTests::MockDocument::Undo() {

}

bool CommandHistoryTests::MockDocument::CanRedo() const {
    return false;
}

void CommandHistoryTests::MockDocument::Redo() {

}

void CommandHistoryTests::MockDocument::Save(const IDocument::Path &path) const {

}

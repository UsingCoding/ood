#include "ConstDocumentItem.hpp"

std::shared_ptr<const IImage> ConstDocumentItem::GetImage() const
{
    return nullptr;
}

std::shared_ptr<const IParagraph> ConstDocumentItem::GetParagraph() const
{
    return nullptr;
}

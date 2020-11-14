#include "ConstDocumentItem.hpp"

std::shared_ptr<const IImage> ConstDocumentItem::GetImage() const
{
    return m_image;
}

std::shared_ptr<const IParagraph> ConstDocumentItem::GetParagraph() const
{
    return m_paragraph;
}

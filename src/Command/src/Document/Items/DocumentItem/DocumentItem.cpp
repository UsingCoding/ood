#include "DocumentItem.hpp"

std::shared_ptr<IImage> DocumentItem::GetImage()
{
    return m_image;
}

std::shared_ptr<IParagraph> DocumentItem::GetParagraph()
{
    return m_paragraph;
}

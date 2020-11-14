#pragma once

#include <memory>
#include "../../Elements/Image/IImage.hpp"
#include "../../Elements/Paragraph/IParagraph.hpp"

class ConstDocumentItem
{
public:
    ConstDocumentItem(
        std::shared_ptr<IImage> image,
        std::shared_ptr<IParagraph> paragraph
    )
    : m_image(image), m_paragraph(paragraph) {}

    std::shared_ptr<const IImage> GetImage()const;
    std::shared_ptr<const IParagraph> GetParagraph()const;

    virtual ~ConstDocumentItem() = default;

protected:
    std::shared_ptr<IImage> m_image;
    std::shared_ptr<IParagraph> m_paragraph;
};


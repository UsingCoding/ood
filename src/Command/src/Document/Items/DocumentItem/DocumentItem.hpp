#pragma once

#include "../ConstDocumentItem/ConstDocumentItem.hpp"

class DocumentItem : public ConstDocumentItem
{
public:
    DocumentItem(
        std::shared_ptr<IImage> image,
        std::shared_ptr<IParagraph> paragraph
    )
    : ConstDocumentItem(image, paragraph) {}

    std::shared_ptr<IImage> GetImage();
    std::shared_ptr<IParagraph> GetParagraph();
};

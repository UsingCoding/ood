#pragma once

#include "../ConstDocumentItem/ConstDocumentItem.hpp"

class DocumentItem : public ConstDocumentItem
{
public:
    std::shared_ptr<IImage> GetImage();
    std::shared_ptr<IParagraph> GetParagraph();
};

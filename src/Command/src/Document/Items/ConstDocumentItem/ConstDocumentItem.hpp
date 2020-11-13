#pragma once

#include <memory>
#include "../../Elements/Image/IImage.hpp"
#include "../../Elements/Paragraph/IParagraph.hpp"

class ConstDocumentItem
{
public:
    std::shared_ptr<const IImage> GetImage()const;
    std::shared_ptr<const IParagraph> GetParagraph()const;

    virtual ~ConstDocumentItem() = default;
};


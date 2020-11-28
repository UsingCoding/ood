#pragma once

#include <string>
#include "../IDocumentConverter.hpp"
#include "../../IDocument.hpp"

class HtmlDocumentConverter : public IDocumentConverter
{
public:
    std::string Convert(const IDocument &document, const std::unique_ptr<IAssetPathPreparer> & pathPreparer) const override;
private:
    std::string ConvertImage(const std::shared_ptr<const IImage> & image, const std::unique_ptr<IAssetPathPreparer> & pathPreparer) const;
    std::string ConvertParagraph(const std::shared_ptr<const IParagraph> & paragraph, const std::unique_ptr<IAssetPathPreparer> & pathPreparer) const;
};

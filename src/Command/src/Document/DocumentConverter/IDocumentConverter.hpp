#pragma once

#include "../IDocument.hpp"
#include "../AssetPathPreparer/IAssetPathPreparer.hpp"

class IDocumentConverter
{
public:
    virtual std::string Convert(const IDocument & document, const std::unique_ptr<IAssetPathPreparer> & pathPreparer) const = 0;
};

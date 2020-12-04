#pragma once

#include "../../../src/Document/DocumentConverter/IDocumentConverter.hpp"

namespace DocumentTests
{
    class MockDocumentConverter : public IDocumentConverter
    {
    public:
        std::string
        Convert(const IDocument &document, const std::unique_ptr<IAssetPathPreparer> &pathPreparer) const override;
    };
}

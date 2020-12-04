#pragma once

#include "../../../src/Document/AssetPathPreparer/IAssetPathPreparer.hpp"

namespace DocumentTests
{
    class MockAssetPathPreparer : public IAssetPathPreparer
    {
    public:
        Path Prepare(const Path &path) override;
    };
}


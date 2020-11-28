#pragma once

#include "../IAssetPathPreparer.hpp"

class RelativeAssetPathPreparer : public IAssetPathPreparer
{
public:
    Path Prepare(const Path & path) override;
};

#pragma once

#include <experimental/filesystem>

class IAssetPathPreparer
{
public:
    typedef std::experimental::filesystem::path Path;

    virtual Path Prepare(const Path & path) = 0;

    ~IAssetPathPreparer() = default;
};

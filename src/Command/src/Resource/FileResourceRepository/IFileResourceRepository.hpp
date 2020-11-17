#pragma once

#include "../FileResource.hpp"

class IFileResourceRepository
{
public:
    typedef std::experimental::filesystem::path Path;

    virtual void Add(std::shared_ptr<FileResource> file) = 0;
    virtual void Delete(std::shared_ptr<FileResource> file) = 0;
    virtual void SetPath(const Path & path) = 0;
    virtual void Clear() = 0;

    virtual ~IFileResourceRepository() = default;
};

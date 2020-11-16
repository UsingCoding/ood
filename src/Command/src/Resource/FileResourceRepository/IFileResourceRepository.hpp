#pragma once

#include "../FileResource.hpp"

class IFileResourceRepository
{
public:
    virtual void Add(std::shared_ptr<FileResource> file) = 0;
    virtual void Delete(std::shared_ptr<FileResource> file) = 0;
    virtual void Clear() = 0;

    virtual ~IFileResourceRepository() = default;
};

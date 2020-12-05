#pragma once

#include "../../../src/Resource/FileResourceRepository/IFileResourceRepository.hpp"

namespace ApplicationTests
{
    class MockFileResourceRepository : public IFileResourceRepository
    {
    public:
        void Add(std::shared_ptr<FileResource> file) override;

        void Delete(std::shared_ptr<FileResource> file) override;

        void SetPath(const Path &path) override;

        void Init() override;

        void Clear() override;
    };
}



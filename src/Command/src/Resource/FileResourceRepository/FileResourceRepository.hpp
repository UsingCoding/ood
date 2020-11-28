#pragma once

#include <map>
#include <experimental/filesystem>

#include "IFileResourceRepository.hpp"

class FileResourceRepository : public IFileResourceRepository
{
public:
    FileResourceRepository(const Path &repoPath);

    void Add(std::shared_ptr<FileResource> file) override;

    void Delete(std::shared_ptr<FileResource> file) override;

    void SetPath(const Path &path) override;

    void Init() override;

    void Clear() override;

private:
    Path m_repoPath;
    std::map<std::string, int> m_fileExtensionOffsetMap;
    std::map<std::string, std::shared_ptr<FileResource>> m_inMemoryFileRepo;
};

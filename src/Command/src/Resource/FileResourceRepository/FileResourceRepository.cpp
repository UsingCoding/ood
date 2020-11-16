#include <Strings.hpp>
#include <algorithm>
#include <iostream>
#include "FileResourceRepository.hpp"

FileResourceRepository::FileResourceRepository(const FileResourceRepository::Path &repoPath) : m_repoPath(repoPath)
{
    if (!std::experimental::filesystem::exists(m_repoPath))
    {
        std::experimental::filesystem::create_directories(m_repoPath);
    }
}

void FileResourceRepository::Add(std::shared_ptr<FileResource> file)
{
    auto fileExtension = file->GetPath().extension();
    auto it = m_fileExtensionOffsetMap.find(fileExtension);

    int currentOffset = it == m_fileExtensionOffsetMap.end() ? 0 : it->second;

    auto newPath = m_repoPath;

    std::string fileId = Strings::Concatenator() << currentOffset << Strings::Trim(fileExtension, "\"");

    newPath /= fileId;

    std::experimental::filesystem::copy(file->GetPath(), newPath);

    file->SetPath(newPath);

    m_inMemoryFileRepo.insert(std::make_pair(fileId, file));
}

void FileResourceRepository::Delete(std::shared_ptr<FileResource> file)
{
    auto searchIt = std::find_if(m_inMemoryFileRepo.begin(), m_inMemoryFileRepo.end(),
    [&file](const std::pair<std::string, std::shared_ptr<FileResource>> & pair){
        return pair.second->GetPath() == file->GetPath();
    });

    if (searchIt == m_inMemoryFileRepo.end())
    {
        throw std::logic_error("No file founded in repository");
    }

    std::experimental::filesystem::remove(file->GetPath());
    m_inMemoryFileRepo.erase(searchIt);
}

void FileResourceRepository::Clear()
{
    std::experimental::filesystem::remove_all(m_repoPath);
}

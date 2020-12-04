#include <Strings.hpp>
#include <algorithm>
#include <iostream>
#include <FileSystem.hpp>
#include "FileResourceRepository.hpp"

FileResourceRepository::FileResourceRepository(const FileResourceRepository::Path &repoPath) : m_repoPath(repoPath)
{

}

void FileResourceRepository::Add(std::shared_ptr<FileResource> file)
{
    auto fileExtension = file->GetPath().extension();
    auto it = m_fileExtensionOffsetMap.find(fileExtension);

    int currentOffset = it == m_fileExtensionOffsetMap.end() ? 0 : it->second + 1;

    auto newPath = m_repoPath;

    std::string fileId = Strings::Concatenator() << currentOffset << Strings::Trim(fileExtension, "\"");

    newPath /= fileId;

    if (std::experimental::filesystem::exists(newPath))
    {
        std::experimental::filesystem::remove(newPath);
    }

    std::experimental::filesystem::copy(file->GetPath(), newPath);

    file->SetPath(newPath);

    m_inMemoryFileRepo.insert(std::make_pair(fileId, file));
    m_fileExtensionOffsetMap.insert(std::make_pair(fileExtension, currentOffset));
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

void FileResourceRepository::SetPath(const IFileResourceRepository::Path &path)
{
    m_repoPath = path;
}

void FileResourceRepository::Clear()
{
    std::experimental::filesystem::remove_all(m_repoPath);
    m_inMemoryFileRepo.clear();
}

void FileResourceRepository::Init()
{
    FileSystem::CreateDirIfNotExists(m_repoPath);
}

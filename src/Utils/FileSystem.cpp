#include "FileSystem.hpp"


void FileSystem::CreateDirIfNotExists(const Path & path)
{
    if (!std::experimental::filesystem::exists(path))
    {
        std::experimental::filesystem::create_directories(path);
    }
}
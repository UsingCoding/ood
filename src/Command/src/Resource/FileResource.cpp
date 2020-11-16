#include "FileResource.hpp"

void FileResource::CopyTo(const FileResource::Path &path)
{

}

void FileResource::Delete()
{

}

const FileResource::Path &FileResource::GetPath() const
{
    return m_path;
}

void FileResource::SetPath(const FileResource::Path &path)
{
    m_path = path;
}

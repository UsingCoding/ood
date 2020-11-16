#pragma once

#include <experimental/filesystem>

class FileResource
{
public:
    typedef std::experimental::filesystem::path Path;

    FileResource(const Path &path) : m_path(path) {}

    void CopyTo(const Path &path);

    void Delete();

    const Path &GetPath() const;

    void SetPath(const Path &path);

private:
    Path m_path;
};


#include <experimental/filesystem>

namespace FileSystem
{
    using namespace std::experimental::filesystem;

    typedef path Path;

    void CreateDirIfNotExists(const Path & path);
}
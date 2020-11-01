#include "FileStreamFactory.hpp"
#include "../../../Input/FileInputStream/FileInputStream.hpp"
#include "../../../Output/FileOutputStream/FileOutputStream.hpp"

std::unique_ptr<IInputDataStream> FileStreamFactory::CreateInputStream(const std::string &name)
{
    return std::make_unique<FileInputStream>(name);
}

std::unique_ptr<IOutputDataStream> FileStreamFactory::CreateOutputStream(const std::string &name)
{
    return std::make_unique<FileOutputStream>(name);
}

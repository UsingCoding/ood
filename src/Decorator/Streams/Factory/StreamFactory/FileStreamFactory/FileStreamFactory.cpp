#include "FileStreamFactory.hpp"

std::unique_ptr<IInputDataStream> FileStreamFactory::CreateInputStream(const std::string &name)
{
    return std::unique_ptr<IInputDataStream>();
}

std::unique_ptr<IOutputDataStream> FileStreamFactory::CreateOutputStream(const std::string &name)
{
    return std::unique_ptr<IOutputDataStream>();
}

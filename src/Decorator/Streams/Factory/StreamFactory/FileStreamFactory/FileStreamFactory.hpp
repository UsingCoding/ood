#pragma once

#include <memory>
#include "../../../Input/IInputDataStream.hpp"
#include "../../../Output/IOutputDataStream.hpp"
#include "../IStreamFactory.hpp"

class FileStreamFactory : public IStreamFactory
{
    std::unique_ptr<IInputDataStream> CreateInputStream(const std::string & name);
    std::unique_ptr<IOutputDataStream> CreateOutputStream(const std::string & name);
};


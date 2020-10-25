#pragma once

#include <memory>
#include "../../Input/IInputDataStream.hpp"
#include "../../Output/IOutputDataStream.hpp"

class IStreamFactory
{
public:
    virtual std::unique_ptr<IInputDataStream> CreateInputStream(const std::string & name) = 0;
    virtual std::unique_ptr<IOutputDataStream> CreateOutputStream(const std::string & name) = 0;
};

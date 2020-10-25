#pragma once

#include "../IStreamFactory.hpp"

class MemoryStreamFactory : public IStreamFactory
{
    std::unique_ptr<IInputDataStream> CreateInputStream(const std::string &name) override;

    std::unique_ptr<IOutputDataStream> CreateOutputStream(const std::string &name) override;
};

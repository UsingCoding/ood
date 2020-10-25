#include "MemoryStreamFactory.hpp"
#include "../../../Output/MemoryOutputStream/MemoryOutputStream.hpp"
#include "../../../Input/MemoryInputStream/MemoryInputStream.hpp"

std::unique_ptr<IInputDataStream> MemoryStreamFactory::CreateInputStream(const std::string &name)
{
    std::string str = "some info";
    std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

    return std::make_unique<MemoryInputStream>(std::move(data));
}

std::unique_ptr<IOutputDataStream> MemoryStreamFactory::CreateOutputStream(const std::string &name)
{
    return std::make_unique<MemoryOutputStream>();
}

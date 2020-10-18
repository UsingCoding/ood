#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Output/MemoryOutputStream/MemoryOutputStream.hpp"

void HandleStreamsFromStream(IInputDataStream & inputDataStream, IOutputDataStream & outputDataStream)
{
    while (!inputDataStream.IsEOF())
    {
        auto byte = inputDataStream.ReadByte();
        std::cout << byte << std::endl;

        outputDataStream.WriteByte(byte);
    }
}

int main()
{
    std::string str = "some info";
    std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

    std::cout << data->size() << std::endl;

    MemoryInputStream inputStream(std::move(data));

    MemoryOutputStream outputStream;

    HandleStreamsFromStream(inputStream, outputStream);
}
#include "TransformApplication.hpp"
#include "../Input/MemoryInputStream/MemoryInputStream.hpp"
#include "../Output/MemoryOutputStream/MemoryOutputStream.hpp"

TransformApplication::TransformApplication()
{

}

void TransformApplication::run(std::istream & istream, std::ostream & ostream)
{
    std::string input;

    std::string str = "some info";
    std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

    MemoryInputStream inputStream(std::move(data));

    MemoryOutputStream outputStream;

    while (getline(istream, input))
    {
        if (input == "--encrypt")
        {

        }
    }
}

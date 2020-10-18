#include <sstream>
#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Output/MemoryOutputStream/MemoryOutputStream.hpp"
#include "Application/TransformApplication.hpp"

int main()
{
    std::string str = "some info";
    std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

    MemoryInputStream inputStream(std::move(data));

    MemoryOutputStream outputStream;

    std::istringstream inputStringStream("--encrypt 3 --encrypt 100500 --compress --encrypt input.dat output.dat");
    std::ostringstream outputStringStream;

    TransformApplication application;

    application.run(inputStringStream, outputStringStream);

    std::cout << outputStringStream.str() << std::endl;
}
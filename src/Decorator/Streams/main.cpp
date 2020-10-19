#include <sstream>
#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Output/MemoryOutputStream/MemoryOutputStream.hpp"
#include "Application/TransformApplication.hpp"

int main()
{
    std::istringstream inputStringStream("--encrypt 3 --encrypt 100500 --compress --encrypt input.dat output.dat");
    std::ostringstream outputStringStream;

    auto inputStreamCreator = [](const std::string && name){
        std::string str = "some info";
        std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

        return std::make_unique<MemoryInputStream>(std::move(data));
    };

    auto outputStreamCreator = [](const std::string && name){
        return std::make_unique<MemoryOutputStream>();
    };

    TransformApplication application(inputStreamCreator, outputStreamCreator);

    application.run(inputStringStream, outputStringStream);

    std::cout << outputStringStream.str() << std::endl;
}
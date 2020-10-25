#include <sstream>
#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Application/TransformApplication.hpp"
#include "Factory/CryptStreamDecoratorFactory/CryptStreamDecoratorFactory.hpp"
#include "Factory/StreamFactory/MemoryStreamFactory/MemoryStreamFactory.hpp"
#include "Factory/CompressStreamDecoratorFactory/CompressStreamDecoratorFactory.hpp"

int main()
{
    std::istringstream inputStringStream("--encrypt 3 --encrypt 100500 --compress --encrypt input.dat output.dat");
    std::ostringstream outputStringStream;

    Encoder encoder;

    TransformApplication application(
        std::make_unique<MemoryStreamFactory>(),
        std::make_unique<CryptStreamDecoratorFactory>(encoder),
        std::make_unique<CompressStreamDecoratorFactory>()
    );

    application.run(inputStringStream, outputStringStream);

    std::cout << outputStringStream.str() << std::endl;
}
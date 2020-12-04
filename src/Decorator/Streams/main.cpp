#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Application/TransformApplication.hpp"
#include "Factory/CryptStreamDecoratorFactory/CryptStreamDecoratorFactory.hpp"
#include "Factory/StreamFactory/MemoryStreamFactory/MemoryStreamFactory.hpp"
#include "Factory/CompressStreamDecoratorFactory/CompressStreamDecoratorFactory.hpp"
#include "Factory/StreamFactory/FileStreamFactory/FileStreamFactory.hpp"

int main(int argc, char const *argv[])
{
    Common::Console::ArgvInput input(argc, argv, std::cin);
    Common::Console::StreamOutput output(std::cout);

    Encoder encoder;

    TransformApplication application(
        std::make_unique<FileStreamFactory>(),
        std::make_unique<CryptStreamDecoratorFactory>(encoder),
        std::make_unique<CompressStreamDecoratorFactory>()
    );

    application.Run(input, output);
}
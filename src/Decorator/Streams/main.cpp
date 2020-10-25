#include "Input/MemoryInputStream/MemoryInputStream.hpp"
#include "Output/IOutputDataStream.hpp"
#include "Application/TransformApplication.hpp"
#include "Factory/CryptStreamDecoratorFactory/CryptStreamDecoratorFactory.hpp"
#include "Factory/StreamFactory/MemoryStreamFactory/MemoryStreamFactory.hpp"
#include "Factory/CompressStreamDecoratorFactory/CompressStreamDecoratorFactory.hpp"

TransformApplication::InputArgs ConvertArgsToInputArgs(int argc, const char **argv)
{
    auto args = std::make_unique<std::vector<std::string>>();

    for (int i = 0; i < argc; ++i)
    {
        args->push_back(argv[i]);
    }

    return std::move(args);
}

int main(int argc, char const *argv[])
{
    Encoder encoder;

    TransformApplication application(
        std::make_unique<MemoryStreamFactory>(),
        std::make_unique<CryptStreamDecoratorFactory>(encoder),
        std::make_unique<CompressStreamDecoratorFactory>()
    );

    application.Run(ConvertArgsToInputArgs(argc, argv));
}
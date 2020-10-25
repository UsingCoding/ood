#include <Strings.hpp>
#include "TransformApplication.hpp"

std::unique_ptr<InputDefinition> TransformApplication::BuildInputDefinition(const InputArgs & inputArgs)
{
    auto definition = std::make_unique<InputDefinition>();

    for (int i = 0; i < inputArgs->size(); ++i)
    {
        auto & arg = (*inputArgs)[i];

        if (Strings::StartsWith(arg, "--"))
        {
            std::string & nextArg = (*inputArgs)[i + 1];

            std::optional<std::string> value;

            if (Strings::StartsWith(nextArg, "--"))
            {
                value = std::nullopt;
            }
            else
            {
                value = nextArg;
                ++i;
            }

            definition->AddOptionalArgument(arg, value);
            continue;
        }

        definition->AddPositionalArgument(arg);
    }

    return std::move(definition);
}

void TransformApplication::Run(const InputArgs & inputArgs)
{
    auto definition = BuildInputDefinition(inputArgs);

    DoRun(std::move(definition));
}

void TransformApplication::DoRun(std::unique_ptr<InputDefinition> inputDefinition)
{
    std::cout << "Run" << std::endl;

    std::cout << "Opt args: " << inputDefinition->GetOptionalArgumentsCount() << std::endl;
    std::cout << "Pos args: " << inputDefinition->GetPositionalArgumentsCount() << std::endl;

    inputDefinition->DoForEachOptionalArgument([](const InputDefinition::OptionalArgumentsContainer::value_type & value){
        std::cout << "Opt arg: " << value.first << ", value: " << value.second.value_or("undefined") << std::endl;
    });

    for (int i = 0; i < inputDefinition->GetPositionalArgumentsCount(); ++i)
    {
        std::cout << "Pos arg: " << inputDefinition->GetPositionalArgument(i) << std::endl;
    }

//    auto inputStream = m_streamFactory->CreateInputStream("name");
//    auto outputStream = m_streamFactory->CreateOutputStream("name");
//
//    std::string input;
//
//    while (!istream.eof())
//    {
//        istream >> input;
//
//        std::cout << input << std::endl;
//
//        if (input == "--encrypt")
//        {
//            int key;
//
//            istream >> key;
//
//            outputStream = m_cryptStreamDecoratorFactory->DecorateEncryptStream(std::move(outputStream), key);
//
//            continue;
//        }
//
//        if (input == "--compress")
//        {
//            outputStream = m_compressStreamDecoratorFactory->DecorateCompressStream(std::move(outputStream));
//
//            continue;
//        }
//
//        if (input == "--decrypt")
//        {
//            int key;
//
//            istream >> key;
//
//            inputStream = m_cryptStreamDecoratorFactory->DecorateDecryptStream(std::move(inputStream), key);
//
//            continue;
//        }
//
//        if (input == "--decompress")
//        {
//            inputStream = m_compressStreamDecoratorFactory->DecorateDecompressStream(std::move(inputStream));
//
//            continue;
//        }
//    }
}

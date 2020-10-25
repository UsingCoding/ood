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
    if (inputDefinition->GetPositionalArgumentsCount() != 3)
    {
        throw std::runtime_error("Invalid count of arguments");
    }

    auto inputStream = m_streamFactory->CreateInputStream(inputDefinition->GetPositionalArgument(1));
    auto outputStream = m_streamFactory->CreateOutputStream(inputDefinition->GetPositionalArgument(2));

    inputDefinition->DoForEachOptionalArgument([&](const InputDefinition::OptionalArgumentsContainer::value_type & value){
        std::cout << "Do: " << value.first << " with value: " << value.second.value_or("no value") << std::endl;

        if (value.first == "--encrypt")
        {
            if (!value.second.has_value())
            {
                throw std::runtime_error("No key provided for encryption");
            }

            outputStream = m_cryptStreamDecoratorFactory->DecorateEncryptStream(std::move(outputStream), std::stoi(value.second.value()));
            return;
        }

        if (value.first == "--decrypt")
        {
            if (!value.second.has_value())
            {
                throw std::runtime_error("No key provided for decryption");
            }

            inputStream = m_cryptStreamDecoratorFactory->DecorateDecryptStream(std::move(inputStream), std::stoi(value.second.value()));
            return;
        }

        if (value.first == "--compress")
        {
            outputStream = m_compressStreamDecoratorFactory->DecorateCompressStream(std::move(outputStream));
            return;
        }

        if (value.first == "--decompress")
        {
            inputStream = m_compressStreamDecoratorFactory->DecorateDecompressStream(std::move(inputStream));
            return;
        }
    });

    while (!inputStream->IsEOF())
    {
        auto byte = inputStream->ReadByte();

        outputStream->WriteByte(byte);
    }
}

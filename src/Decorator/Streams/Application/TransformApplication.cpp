#include <Strings.hpp>
#include "TransformApplication.hpp"

void TransformApplication::Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddOption(Common::Console::InputOption(
        (std::string) COMPRESS_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_NONE
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) DECOMPRESS_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_NONE
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) ENCRYPT_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_REQUIRED
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) DECRYPT_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_REQUIRED
    ));

    definition->AddArgument(Common::Console::InputArgument((std::string) INPUT_FILE_KEY));
    definition->AddArgument(Common::Console::InputArgument((std::string) OUTPUT_FILE_KEY));
}

void TransformApplication::DoRun(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    auto inputStream = m_streamFactory->CreateInputStream(input.GetArgument((std::string) INPUT_FILE_KEY).value());
    auto outputStream = m_streamFactory->CreateOutputStream(input.GetArgument((std::string) OUTPUT_FILE_KEY).value());

    input.GetOptionsEnumerator().ForEach([&](const std::string & name, const std::optional<std::string> & value){
        (*output) << "Do: " << name << " with value: " << value.value_or("no value") << std::endl;

        if (name == "--encrypt")
        {
            outputStream = m_cryptStreamDecoratorFactory->DecorateEncryptStream(std::move(outputStream), std::stoi(value.value()));
            return;
        }

        if (name == "--decrypt")
        {
            inputStream = m_cryptStreamDecoratorFactory->DecorateDecryptStream(std::move(inputStream), std::stoi(value.value()));
            return;
        }

        if (name == "--compress")
        {
            outputStream = m_compressStreamDecoratorFactory->DecorateCompressStream(std::move(outputStream));
            return;
        }

        if (name == "--decompress")
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

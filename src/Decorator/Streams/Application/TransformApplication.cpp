#include <Strings.hpp>
#include "TransformApplication.hpp"

void TransformApplication::Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{
    definition->AddOption(Common::Console::InputOption(
        (std::string) COMPRESS_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_NONE,
        Common::Console::InputOption::MultipleMode::MULTIPLE
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) DECOMPRESS_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_NONE,
        Common::Console::InputOption::MultipleMode::MULTIPLE
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) ENCRYPT_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_REQUIRED,
        Common::Console::InputOption::MultipleMode::MULTIPLE
    ));

    definition->AddOption(Common::Console::InputOption(
        (std::string) DECRYPT_KEY,
        std::nullopt,
        Common::Console::InputOption::ValueMode::VALUE_REQUIRED,
        Common::Console::InputOption::MultipleMode::MULTIPLE
    ));

    definition->AddArgument(Common::Console::InputArgument((std::string) INPUT_FILE_KEY));
    definition->AddArgument(Common::Console::InputArgument((std::string) OUTPUT_FILE_KEY));
}

void TransformApplication::DoRun(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    auto inputStream = m_streamFactory->CreateInputStream(input.GetArgument((std::string) INPUT_FILE_KEY).value());
    auto outputStream = m_streamFactory->CreateOutputStream(input.GetArgument((std::string) OUTPUT_FILE_KEY).value());

    DecorateStreams(inputStream, outputStream, input);

    *(output) << "Reading:" << std::endl;

    while (!inputStream->IsEOF())
    {
        auto byte = inputStream->ReadByte();

        std::cout << byte;

        outputStream->WriteByte(byte);
    }
}

void TransformApplication::DecorateStreams(
    std::unique_ptr<IInputDataStream> & inputDataStream,
    std::unique_ptr<IOutputDataStream> & outputDataStream,
    Common::Console::IInput &input
    )
{
    std::vector<std::pair<std::string, std::optional<std::string>>> inputDecorations;
    std::vector<std::pair<std::string, std::optional<std::string>>> outputDecorations;

    input.GetOptionsEnumerator().ForEach([&inputDecorations, &outputDecorations](const std::string & name, const std::optional<std::string> & value){
        if (name == ENCRYPT_KEY)
        {
            outputDecorations.push_back(std::pair((std::string) ENCRYPT_KEY, value));
            return;
        }

        if (name == DECRYPT_KEY)
        {
            inputDecorations.push_back(std::pair((std::string) DECRYPT_KEY, value));
            return;
        }

        if (name == COMPRESS_KEY)
        {
            outputDecorations.push_back(std::pair((std::string) COMPRESS_KEY, value));
            return;
        }

        if (name == DECOMPRESS_KEY)
        {
            inputDecorations.push_back(std::pair((std::string) DECOMPRESS_KEY, value));
            return;
        }
    });

    std::for_each(inputDecorations.begin(), inputDecorations.end(), [&](const std::pair<std::string, std::optional<std::string>> & decoration){
        if (decoration.first == DECRYPT_KEY)
        {
            inputDataStream = m_cryptStreamDecoratorFactory->DecorateDecryptStream(std::move(inputDataStream), std::stoi(decoration.second.value()));
            return;
        }

        if (decoration.first == DECOMPRESS_KEY)
        {
            inputDataStream = m_compressStreamDecoratorFactory->DecorateDecompressStream(std::move(inputDataStream));
            return;
        }
    });

    std::for_each(outputDecorations.rbegin(), outputDecorations.rend(), [&](const std::pair<std::string, std::optional<std::string>> & decoration){
        if (decoration.first == ENCRYPT_KEY)
        {
            outputDataStream = m_cryptStreamDecoratorFactory->DecorateEncryptStream(std::move(outputDataStream), std::stoi(decoration.second.value()));
            return;
        }

        if (decoration.first == COMPRESS_KEY)
        {
            outputDataStream = m_compressStreamDecoratorFactory->DecorateCompressStream(std::move(outputDataStream));
            return;
        }
    });
}

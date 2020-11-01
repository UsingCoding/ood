#pragma once

#include <memory>
#include <functional>
#include <vector>
#include <Application/Application.hpp>

#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"
#include "../Factory/CryptStreamDecoratorFactory/ICryptStreamDecoratorFactory.hpp"
#include "../Factory/StreamFactory/IStreamFactory.hpp"
#include "../Factory/CompressStreamDecoratorFactory/ICompressStreamDecoratorFactory.hpp"
#include "Input/InputDefinition/InputDefinition.hpp"

class TransformApplication : public Common::Application
{
public:
    TransformApplication(
        std::unique_ptr<IStreamFactory> streamFactory,
        std::unique_ptr<ICryptStreamDecoratorFactory> cryptStreamDecoratorFactory,
        std::unique_ptr<ICompressStreamDecoratorFactory> compressStreamDecoratorFactory
    ) :
        m_streamFactory(std::move(streamFactory)),
        m_cryptStreamDecoratorFactory(std::move(cryptStreamDecoratorFactory)),
        m_compressStreamDecoratorFactory(std::move(compressStreamDecoratorFactory))
        {}

private:
    void Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void DoRun(Common::Console::IInput &input, Common::Console::IOutput &output) override;

    std::unique_ptr<IStreamFactory> m_streamFactory;
    std::unique_ptr<ICryptStreamDecoratorFactory> m_cryptStreamDecoratorFactory;
    std::unique_ptr<ICompressStreamDecoratorFactory> m_compressStreamDecoratorFactory;

    constexpr static std::string_view COMPRESS_KEY = "compress";
    constexpr static std::string_view DECOMPRESS_KEY = "decompress";
    constexpr static std::string_view ENCRYPT_KEY = "encrypt";
    constexpr static std::string_view DECRYPT_KEY = "decrypt";

    constexpr static std::string_view INPUT_FILE_KEY = "input_file";
    constexpr static std::string_view OUTPUT_FILE_KEY = "output_file";
};

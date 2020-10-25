#include "TransformApplication.hpp"
#include "../Input/MemoryInputStream/MemoryInputStream.hpp"
#include "../Output/EncryptOutputDecoratorStream/EncryptOutputDecoratorStream.hpp"
#include "../Output/CompressOutputDecoratorStream/CompressOutputDecoratorStream.hpp"
#include "../Input/DecompressInputStreamDecorator/DecompressInputStreamDecorator.hpp"
#include "../Input/DecryptInputStreamDecorator/DecryptInputStreamDecorator.hpp"

TransformApplication::TransformApplication(
        const std::function<std::unique_ptr<IInputDataStream>(const std::string &&)> &mInputStreamCreator,
        const std::function<std::unique_ptr<IOutputDataStream>(const std::string &&)> &mOutputStreamCreator,
        std::unique_ptr<ICryptStreamDecoratorFactory> cryptStreamDecoratorFactory)
        : m_inputStreamCreator(mInputStreamCreator),
          m_outputStreamCreator(mOutputStreamCreator),
          m_cryptStreamDecoratorFactory(std::move(cryptStreamDecoratorFactory))
        {}

void TransformApplication::run(std::istream & istream, std::ostream & ostream)
{
    std::unique_ptr<IInputDataStream> inputStream = m_inputStreamCreator("name");
    std::unique_ptr<IOutputDataStream> outputStream = m_outputStreamCreator("name");

    std::string input;

    while (!istream.eof())
    {
        istream >> input;

        std::cout << input << std::endl;

        if (input == "--encrypt")
        {
            int key;

            istream >> key;

            outputStream = m_cryptStreamDecoratorFactory->DecorateEncryptStream(std::move(outputStream), key);

            continue;
        }

        if (input == "--compress")
        {
            outputStream = std::make_unique<CompressOutputDecoratorStream>(std::move(outputStream));

            continue;
        }

        if (input == "--decrypt")
        {
            int key;

            istream >> key;

            inputStream = m_cryptStreamDecoratorFactory->DecorateDecryptStream(std::move(inputStream), key);

            continue;
        }

        if (input == "--decompress")
        {
            inputStream = std::make_unique<DecompressInputStreamDecorator>(std::move(inputStream));

            continue;
        }
    }
}

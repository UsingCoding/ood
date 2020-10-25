#include "TransformApplication.hpp"
#include "../Input/MemoryInputStream/MemoryInputStream.hpp"
#include "../Output/CompressOutputDecoratorStream/CompressOutputDecoratorStream.hpp"
#include "../Input/DecompressInputStreamDecorator/DecompressInputStreamDecorator.hpp"


void TransformApplication::run(std::istream & istream, std::ostream & ostream)
{
    auto inputStream = m_streamFactory->CreateInputStream("name");
    auto outputStream = m_streamFactory->CreateOutputStream("name");

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

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../Streams/Input/MemoryInputStream/MemoryInputStream.hpp"
#include "../Streams/Crypt/Encoder.hpp"
#include "../Streams/Factory/CryptStreamDecoratorFactory/CryptStreamDecoratorFactory.hpp"
#include "../Streams/Output/MemoryOutputStream/MemoryOutputStream.hpp"

SCENARIO("Decorate memory stream twice with encrypt and decrypt to get source data")
{
    GIVEN("MemoryInputStream with string and empty MemoryOutputStream")
    {
        std::string str = "some info";
        std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

        std::vector<uint8_t> outputBuffer;

        auto inputStream = std::make_unique<MemoryInputStream>(std::move(data));
        auto outputStream = std::make_unique<MemoryOutputStream>(outputBuffer);

        AND_GIVEN("Decorator factory")
        {
            Encoder encoder;

            CryptStreamDecoratorFactory decoratorFactory(encoder);

            WHEN("We decorate twice with encrypt with key 4 and 6")
            {
                auto decoratedOutputStream = decoratorFactory.DecorateEncryptStream(std::move(outputStream), 4);
                decoratedOutputStream = decoratorFactory.DecorateEncryptStream(std::move(decoratedOutputStream), 6);

                AND_WHEN("We create new streams to decrypt data")
                {
                    auto decoratedInputStream = decoratorFactory.DecorateDecryptStream(std::move(inputStream), 4);
                    decoratedInputStream = decoratorFactory.DecorateDecryptStream(std::move(decoratedInputStream), 6);

                    AND_WHEN("We write and read data")
                    {
                        while (!decoratedInputStream->IsEOF())
                        {
                            auto byte = decoratedInputStream->ReadByte();

                            decoratedOutputStream->WriteByte(byte);
                        }

                        THEN("We have identical data that we passed into input stream")
                        {
                            for (auto i = 0; i < outputBuffer.size(); i++)
                            {
                                REQUIRE((outputBuffer[i] == str[i]));
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Passing data into stream and read write without decorating")
{
    GIVEN("MemoryInputStream with string and empty MemoryOutputStream")
    {
        std::string str = "some info";
        std::unique_ptr<std::vector<uint8_t>> data = std::make_unique<std::vector<uint8_t>>(str.begin(), str.end());

        auto outputBuffer = std::make_shared<std::vector<uint8_t>>();

        auto inputStream = std::make_unique<MemoryInputStream>(std::move(data));
        auto outputStream = std::make_unique<MemoryOutputStream>(outputBuffer);

        WHEN("We read and write data in streams to eof")
        {
            while (!inputStream->IsEOF())
            {
                auto byte = inputStream->ReadByte();

                outputStream->WriteByte(byte);
            }

            THEN("We have a source data")
            {
                for (auto i = 0; i < outputBuffer.size(); i++)
                {
                    REQUIRE((outputBuffer[i] == str[i]));
                }
            }
        }
    }
}
#include "EncryptOutputDecoratorStream.hpp"

void EncryptOutputDecoratorStream::WriteByte(uint8_t data)
{
    auto byte = m_encoder.Encode(data, m_key);

    m_stream->WriteByte(byte);
}

void EncryptOutputDecoratorStream::WriteBlock(const void *srcData, std::streamsize size)
{

}
#include "CompressOutputDecoratorStream.hpp"


void CompressOutputDecoratorStream::WriteByte(uint8_t data)
{
    m_stream->WriteByte(data);
}

void CompressOutputDecoratorStream::WriteBlock(const void *srcData, std::streamsize size)
{

}


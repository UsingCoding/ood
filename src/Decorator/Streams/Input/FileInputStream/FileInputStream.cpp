#include "FileInputStream.hpp"

bool FileInputStream::IsEOF() const
{
    return m_fin.eof();
}

uint8_t FileInputStream::ReadByte()
{
    char byte[1] = {};

    m_fin.read(byte, sizeof(byte));

    return byte[0];
}

std::streamsize FileInputStream::ReadBlock(void *dstBuffer, std::streamsize size)
{
    return 0;
}

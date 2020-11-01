#include "FileInputStream.hpp"

bool FileInputStream::IsEOF() const
{
    return m_fin.eof();
}

uint8_t FileInputStream::ReadByte()
{
    char byte;

    if (!m_fin.read(&byte, 1))
    {
        throw std::ios_base::failure("Cannot read byte");
    }

    return (uint8_t) byte;
}

std::streamsize FileInputStream::ReadBlock(void *dstBuffer, std::streamsize size)
{
    if (!m_fin.read(static_cast<char*>(dstBuffer), size))
    {
        throw std::ios_base::failure("Cannot read block");
    }

    return m_fin.gcount();
}


#include <iostream>
#include "FileOutputStream.hpp"

void FileOutputStream::WriteByte(uint8_t data)
{
    if(!m_fout.write((char*) &data, sizeof(data)))
    {
        throw std::ios_base::failure("Cannot write byte.");
    }
}

void FileOutputStream::WriteBlock(const void *srcData, std::streamsize size)
{
    const char* dataPtr = static_cast<const char*>(srcData);

    if (!m_fout.write(dataPtr, size))
    {
        throw std::ios_base::failure("Cannot write block.");
    }
}

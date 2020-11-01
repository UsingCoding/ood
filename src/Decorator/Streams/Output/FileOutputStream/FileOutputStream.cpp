
#include <iostream>
#include "FileOutputStream.hpp"

void FileOutputStream::WriteByte(uint8_t data)
{
    m_fout.write((char*) &data, sizeof(data));
}

void FileOutputStream::WriteBlock(const void *srcData, std::streamsize size)
{

}

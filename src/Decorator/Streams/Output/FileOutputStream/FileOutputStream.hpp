#pragma once

#include <fstream>
#include "../IOutputDataStream.hpp"

class FileOutputStream : public IOutputDataStream
{
public:
    FileOutputStream(const std::string & name)
    {
        m_fout.open(name, std::ios::binary);

        if (!m_fout.is_open())
        {
            throw std::runtime_error("Can`t open file " + name);
        }
    }

    void WriteByte(uint8_t data) override;

    void WriteBlock(const void *srcData, std::streamsize size) override;

private:
    std::ofstream m_fout;
};

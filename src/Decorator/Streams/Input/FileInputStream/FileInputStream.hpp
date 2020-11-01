#pragma once

#include <fstream>
#include "../IInputDataStream.hpp"

class FileInputStream : public IInputDataStream
{
public:
    FileInputStream(const std::string & name)
    {
        m_fin.open(name, std::ios::in | std::ios::binary);

        if (!m_fin.is_open())
        {
            throw std::runtime_error("Can`t open file " + name);
        }
    }

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void *dstBuffer, std::streamsize size) override;

private:
    std::ifstream m_fin;
};

#pragma once

#include <string>
#include <cstdint>
#include <memory>

class IOutputDataStream
{
public:
    typedef std::unique_ptr<IOutputDataStream> OutputDataStreamPtr;

    IOutputDataStream() {};

    // Записывает в поток данных байт
    // Выбрасывает исключение std::ios_base::failure в случае ошибки
    virtual void WriteByte(uint8_t data) = 0;

    // Записывает в поток блок данных размером size байт,
    // располагающийся по адресу srcData,
    // В случае ошибки выбрасывает исключение std::ios_base::failure
    virtual void WriteBlock(const void * srcData, std::streamsize size) = 0;

    IOutputDataStream(const IOutputDataStream & dataStream) = delete;

    virtual ~IOutputDataStream() = default;
};

#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <memory>

class IInputDataStream
{
public:
    typedef std::unique_ptr<IInputDataStream> InputDataStreamPtr;

    IInputDataStream() {};

    // Возвращает признак достижения конца данных потока
    // Выбрасывает исключение std::ios_base::failuer в случае ошибки
    virtual bool IsEOF() const = 0;

    // Считывает байт из потока.
    // Выбрасывает исключение std::ios_base::failure в случае ошибки
    virtual uint8_t ReadByte() = 0;

    // Считывает из потока блок данных размером size байт, записывая его в память
    // по адресу dstBuffer
    // Возвращает количество реально прочитанных байт. Выбрасывает исключение в случае ошибки
    virtual std::streamsize ReadBlock(void * dstBuffer, std::streamsize size) = 0;

    IInputDataStream(const IInputDataStream & dataStream) = delete;

    virtual ~IInputDataStream() = default;
};
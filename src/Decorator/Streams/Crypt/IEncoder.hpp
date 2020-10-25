#pragma once

class IEncoder
{
public:
    virtual uint8_t Encode(uint8_t byte, int key) const = 0;
    virtual ~IEncoder() = default;
};

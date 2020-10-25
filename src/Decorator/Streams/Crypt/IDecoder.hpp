#pragma once

#include <cstdint>

class IDecoder
{
public:
    virtual uint8_t Decode(uint8_t byte, int key) const = 0;
    virtual ~IDecoder() = default;
};

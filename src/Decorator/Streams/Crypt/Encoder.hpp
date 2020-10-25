#pragma once

#include <cstdint>
#include "IEncoder.hpp"
#include "IDecoder.hpp"

class Encoder : public IEncoder, public IDecoder
{
public:
    uint8_t Encode(uint8_t byte, int key) const;
    uint8_t Decode(uint8_t byte, int key) const;
};

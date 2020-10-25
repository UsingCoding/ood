#include "Encoder.hpp"

uint8_t Encoder::Encode(uint8_t byte, int key) const
{
    byte ^= key;

    return ((byte & 0b00000111) << 2)
           | ((byte & 0b00011000) << 3)
           | ((byte & 0b01100000) >> 5)
           | ((byte & 0b10000000) >> 2);
}

uint8_t Encoder::Decode(uint8_t byte, int key) const
{
    byte = ((byte & 0b00000011) << 5)
           | ((byte & 0b00011100) >> 2)
           | ((byte & 0b00100000) << 2)
           | ((byte & 0b11000000) >> 3);

    return byte ^ key;
}

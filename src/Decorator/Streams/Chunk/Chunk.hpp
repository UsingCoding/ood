#pragma once

struct Chunk
{
    uint8_t countOfBytes = 0;
    uint8_t byte{};

    void Reset()
    {
        countOfBytes = 0;
    }

    bool IsEmpty()
    {
        return countOfBytes == 0;
    }
};

#pragma once
#include <string>
#include <stdexcept>

enum class Color
{
    GREEN,
    RED,
    BLUE,
    YELLOW,
    PINK,
    BLACK
};

static std::string GetHex(Color color)
{
    switch (color)
    {
        case Color::GREEN:
            return "#00FF00";
        case Color::RED:
            return "#FF0000";
        case Color::BLUE:
            return "#0000FF";
        case Color::YELLOW:
            return "#FFFF00";
        case Color::PINK:
            return "#FFC0CB";
        case Color::BLACK:
            return "#000000";
        default:
            throw std::invalid_argument("Unknown color");
    }
}


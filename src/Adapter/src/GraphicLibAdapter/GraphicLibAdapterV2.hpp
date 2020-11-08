#pragma once

#include <optional>
#include "../GraphicsLib/GraphicLib.hpp"
#include "../ModernGraphicsLib/ModernGraphicsLib.hpp"

namespace app
{
    class GraphicLibAdapterV2 : public graphics_lib::ICanvas, private modern_graphics_lib::CModernGraphicsRenderer
    {
    private:
        struct Coord
        {
            Coord(int x, int y) : m_x(x), m_y(y) {}

            int m_x, m_y;

            operator modern_graphics_lib::CPoint()
            {
                return modern_graphics_lib::CPoint(m_x, m_y);
            }
        };

    public:
        GraphicLibAdapterV2(std::ostream & strm) : modern_graphics_lib::CModernGraphicsRenderer(strm)
        {
            BeginDraw();
        }

        void SetColor(uint32_t rgbColor) override
        {
            auto colorConverter = [](int color) {
                return (float) color / 255;
            };

            m_color = modern_graphics_lib::CRGBAColor{
                    colorConverter(rgbColor / 0x10000),
                    colorConverter(rgbColor / 0x100 % 0x100),
                    colorConverter(rgbColor % 0x100),
                    DEFAULT_ALPHA_CHANNEL};
        }

        void MoveTo(int x, int y) override
        {
            m_currCoord = {x, y};
        }

        void LineTo(int x, int y) override
        {
            DrawLine(m_currCoord.value_or(Coord{0, 0}), {x, y}, m_color);
        }

    private:
        std::optional<Coord> m_currCoord = std::nullopt;
        modern_graphics_lib::CRGBAColor m_color = {0.0, 0.0, 0.0, 0.0};

        const static int DEFAULT_ALPHA_CHANNEL = 1;
    };
}


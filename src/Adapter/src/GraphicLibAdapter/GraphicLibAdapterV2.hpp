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

        void MoveTo(int x, int y) override
        {
            m_currCoord = {x, y};
        }

        void LineTo(int x, int y) override
        {
            DrawLine(m_currCoord.value_or(Coord{0, 0}), {x, y});
        }

    private:
        std::optional<Coord> m_currCoord = std::nullopt;
    };
}


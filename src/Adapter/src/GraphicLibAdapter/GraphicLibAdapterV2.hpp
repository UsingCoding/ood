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

            friend bool operator ==(const Coord & c1, const Coord & c2)
            {
                return c1.m_x == c2.m_x && c1.m_y == c2.m_y;
            }
        };

    public:
        GraphicLibAdapterV2(std::ostream & strm) : modern_graphics_lib::CModernGraphicsRenderer(strm)
        {

        }

        void MoveTo(int x, int y) override
        {
            Coord coord(x, y);

            if (m_beginCoords == std::nullopt)
            {
                m_beginCoords = coord;
                m_currCoord = coord;
                BeginDraw();
                return;
            }

            m_currCoord = coord;
        }

        void LineTo(int x, int y) override
        {
            Coord coord(x, y);

            if (m_beginCoords == std::nullopt)
            {
                m_beginCoords = {0, 0};
                m_currCoord = {x, y};

                BeginDraw();
            }

            DrawLine(m_currCoord.value(), coord);

            if (m_beginCoords.value() == coord)
            {
                EndDraw();
                m_beginCoords = std::nullopt;
                m_currCoord = std::nullopt;
                return;
            }
        }

    private:
        std::optional<Coord> m_currCoord = std::nullopt;
        std::optional<Coord> m_beginCoords = std::nullopt;
    };
}


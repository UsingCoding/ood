#pragma once

#include <optional>
#include "../GraphicsLib/GraphicLib.hpp"
#include "../ModernGraphicsLib/ModernGraphicsLib.hpp"

namespace app
{
    class GraphicLibAdapter : public graphics_lib::ICanvas
    {
    private:
        struct Coord
        {
            Coord() {}
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

            void SetNewCoords(int x, int y)
            {
                m_x = x;
                m_y = y;
            }
        };

    public:
        GraphicLibAdapter(modern_graphics_lib::CModernGraphicsRenderer &renderer) : m_renderer(renderer) {}

        void MoveTo(int x, int y) override
        {
            Coord coord(x, y);

            if (m_beginCoords == std::nullopt)
            {
                m_beginCoords = coord;
                m_currCoord = coord;
                m_renderer.BeginDraw();
                return;
            }

            m_currCoord = coord;
        }

        void LineTo(int x, int y) override
        {
            Coord coord(x, y);

            m_renderer.DrawLine(m_currCoord.value(), coord);

            if (m_beginCoords.value() == coord)
            {
                m_renderer.EndDraw();
                m_beginCoords = std::nullopt;
                m_currCoord = std::nullopt;
                return;
            }
        }

    private:
        modern_graphics_lib::CModernGraphicsRenderer & m_renderer;
        std::optional<Coord> m_currCoord = std::nullopt;
        std::optional<Coord> m_beginCoords = std::nullopt;
    };
}


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
            Coord(int x, int y) : m_x(x), m_y(y) {}

            int m_x, m_y;

            operator modern_graphics_lib::CPoint()
            {
                return modern_graphics_lib::CPoint(m_x, m_y);
            }
        };

    public:
        GraphicLibAdapter(modern_graphics_lib::CModernGraphicsRenderer &renderer) : m_renderer(renderer)
        {
            m_renderer.BeginDraw();
        }

        void MoveTo(int x, int y) override
        {
            m_currCoord = {x, y};
        }

        void LineTo(int x, int y) override
        {
            m_renderer.DrawLine(m_currCoord.value_or(Coord{0, 0}), {x, y});
        }

    private:
        modern_graphics_lib::CModernGraphicsRenderer & m_renderer;
        std::optional<Coord> m_currCoord = std::nullopt;
    };
}


#pragma once

#include "../GraphicsLib/GraphicLib.hpp"
#include "../ModernGraphicsLib/ModernGraphicsLib.hpp"

namespace app
{
    class GraphicLibAdapter : public graphics_lib::ICanvas
    {
    private:
        struct Coord
        {
            int m_x, m_y;

            operator modern_graphics_lib::CPoint()
            {
                return modern_graphics_lib::CPoint(m_x, m_y);
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
            m_currCoord.SetNewCoords(x, y);
        }

        void LineTo(int x, int y) override
        {
            m_renderer.BeginDraw();

            m_renderer.DrawLine(m_currCoord, modern_graphics_lib::CPoint(x, y));

            m_renderer.EndDraw();
        }

    private:
        modern_graphics_lib::CModernGraphicsRenderer & m_renderer;
        Coord m_currCoord;
    };
}


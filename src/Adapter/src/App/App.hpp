#pragma once

#include "../ShapeDrawningLib/ShapeDrawningLib.hpp"
#include "../ModernGraphicsLib/ModernGraphicsLib.hpp"
#include "../GraphicLibAdapter/GraphicLibAdapter.hpp"
#include "../GraphicLibAdapter/GraphicLibAdapterV2.hpp"

namespace app
{
    void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
    {
        using namespace shape_drawing_lib;

        CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
        LeftTopTriangle leftTopTriangle({10, 15 }, {100, 200 });
        CRectangle rectangle({ 30, 40 }, 18, 24);

        painter.Draw(triangle);
        painter.Draw(leftTopTriangle);
        painter.Draw(rectangle);
    }

    void PaintPictureOnCanvas()
    {
        graphics_lib::CCanvas simpleCanvas;
        shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
        PaintPicture(painter);
    }

    void PaintPictureOnModernGraphicsRenderer()
    {
        modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);

        GraphicLibAdapter adapter(renderer);

        shape_drawing_lib::CCanvasPainter painter(adapter);

        PaintPicture(painter);
    }
}

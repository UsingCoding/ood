#include "Painter.hpp"

void Painter::DrawPicture(PictureDraft &draft, ICanvas &canvas)
{
    for (int i = 0; i < draft.GetShapeCount(); ++i)
    {
        auto & shape = draft.GetShape(i);

        shape->Draw(canvas);
    }
}

#pragma once

#include "../Canvas/ICanvas.hpp"
#include "../PictureDraft/PictureDraft.hpp"

class Painter
{
public:
    void DrawPicture(PictureDraft & draft, ICanvas & canvas);
};

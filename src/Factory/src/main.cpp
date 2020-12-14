#include <iostream>
#include "Painter/Painter.hpp"
#include "Factory/ShapeFactory.hpp"
#include "Designer/Designer.hpp"
#include "Canvas/Canvas.hpp"

int main()
{
    ShapeFactory factory;
    Designer designer(factory);

    auto draft = designer.CreateDraft(std::cin);

    Canvas canvas(std::cout);

    Painter painter;

    painter.DrawPicture(*draft, canvas);
}
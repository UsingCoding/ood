#include "Shape/Canvas.hpp"
#include "Shape/Ellipse.hpp"
#include "Shape/ShapeGroup.hpp"
#include "Shape/Rectangle.hpp"
#include "Slide/Slide.hpp"
#include "Shape/Triangle.hpp"
#include <iostream>

const double SLIDE_WIDTH = 800;
const double SLIDE_HEIGHT = 600;

enum HouseColors : RGBAColor
{
    RoofColor = 0x473925FF,
    FacadeColor = 0xB39F82FF,
    WindowColor = 0x7AD2EBFF,
    DoorColor = 0x473925FF,
};

enum WorldColor : RGBAColor
{
    SunColor = 0xEBE244FF,
    SunRayColor = 0xEBE79D99,
    GrassColor = 0x15A315FF,
};

std::shared_ptr<IShape> CreateHouse()
{
    std::shared_ptr<IShape> roof = std::make_shared<CTriangle>(PointD{ 25, 250 }, PointD{ 150, 150 }, PointD{ 275, 250 });
    roof->GetFillStyle()->Enable(true);
    roof->GetFillStyle()->SetColor(HouseColors::RoofColor);
    roof->GetOutlineStyle()->Enable(true);
    roof->GetOutlineStyle()->SetColor(HouseColors::FacadeColor);
    roof->GetOutlineStyle()->SetThickness(10.0);

    std::shared_ptr<IShape> facade = std::make_shared<CRectangle>(PointD{ 50, 250 }, 200, 200);
    facade->GetFillStyle()->Enable(true);
    facade->GetFillStyle()->SetColor(HouseColors::FacadeColor);
    facade->GetOutlineStyle()->Enable(false);

    std::shared_ptr<IShape> window = std::make_shared<CEllipse>(PointD{ 100, 325 }, 25, 25);
    window->GetFillStyle()->Enable(true);
    window->GetFillStyle()->SetColor(HouseColors::WindowColor);
    facade->GetOutlineStyle()->Enable(false);

    std::shared_ptr<IShape> door = std::make_shared<CRectangle>(PointD{ 150, 325 }, 75, 125);
    door->GetFillStyle()->Enable(true);
    door->GetFillStyle()->SetColor(HouseColors::DoorColor);
    door->GetOutlineStyle()->Enable(false);

    std::shared_ptr<IShape> house = std::make_shared<CShapeGroup>();
    house->GetGroup()->InsertShape(roof);
    house->GetGroup()->InsertShape(facade);
    house->GetGroup()->InsertShape(window);
    house->GetGroup()->InsertShape(door);

    return house;
}

std::shared_ptr<IShape> CreateScaledHouse()
{
    auto house = CreateHouse();

    auto empty = std::make_shared<CShapeGroup>();
    house->GetGroup()->InsertShape(empty);

    house->SetFrame({{420, 230}, 320, 200 });

    house->GetFillStyle()->Enable(false);
    house->GetOutlineStyle()->Enable(true);
    house->GetOutlineStyle()->SetColor(HouseColors::WindowColor);
    house->GetOutlineStyle()->SetThickness(3);

    return house;
}

std::shared_ptr<IShape> CreateWorld()
{
    std::shared_ptr<IShape> sun = std::make_shared<CEllipse>(PointD{ 500, 50 }, 50, 50);
    sun->GetFillStyle()->Enable(true);
    sun->GetFillStyle()->SetColor(WorldColor::SunColor);
    sun->GetOutlineStyle()->Enable(true);
    sun->GetOutlineStyle()->SetColor(WorldColor::SunRayColor);
    sun->GetOutlineStyle()->SetThickness(30);

    std::shared_ptr<IShape> grass = std::make_shared<CRectangle>(PointD{ 0, 450 }, 800, 150);
    grass->GetFillStyle()->Enable(true);
    grass->GetFillStyle()->SetColor(WorldColor::GrassColor);
    grass->GetOutlineStyle()->Enable(false);

    std::shared_ptr<IShape> grass2 = std::make_shared<CEllipse>(PointD{ 580, 480 }, 200, 70);
    grass2->GetFillStyle()->Enable(true);
    grass2->GetFillStyle()->SetColor(WorldColor::GrassColor);
    grass2->GetOutlineStyle()->Enable(false);

    auto house = CreateHouse();
    auto scaledHouse = CreateScaledHouse();

    std::shared_ptr<IShape> world = std::make_shared<CShapeGroup>();

    world->GetGroup()->InsertShape(sun);
    world->GetGroup()->InsertShape(grass);
    world->GetGroup()->InsertShape(grass2);
    world->GetGroup()->InsertShape(house);
    world->GetGroup()->InsertShape(scaledHouse);

    return world;
}

std::shared_ptr<ISlide> CreateSlide()
{
    return std::make_shared<CSlide>(SLIDE_WIDTH, SLIDE_HEIGHT);
}

void Draw(std::shared_ptr<ISlide> slide)
{
    Canvas canvas(std::cout);

    slide->Draw(canvas);
}

int main()
{
    auto world = CreateWorld();

    auto slide = CreateSlide();
    slide->InsertShape(world);

    Draw(slide);

    return 0;
}

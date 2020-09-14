#include <iostream>
#include "Ducks/ReadHeadDuck/ReadHeadDuck.hpp"
#include "Ducks/DecoyDuck/DecoyDuck.hpp"
#include "Ducks/MallardDuck/MallardDuck.hpp"

int main()
{
    {
        auto duck = ReadHeadDuck();

        duck.Fly();
        duck.Dance(20);
        duck.Display();
    }

    {
        auto duck = DecoyDuck();

        duck.Fly();
        duck.Dance(10000);
        duck.Display();
    }

    {
        auto duck = MallardDuck();

        duck.Fly();
        duck.Dance(100);
        duck.Fly();

        int counter = 0;

        duck.SetFlyCounter([&counter](){
            ++counter;
            std::cout << "Flight number " << counter << std::endl;
        });

        duck.Fly();
        duck.Fly();
        duck.Fly();
        duck.Display();
    }

    return 0;
}

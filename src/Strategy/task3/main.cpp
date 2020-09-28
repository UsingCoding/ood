#include <iostream>
#include "Ducks/ReadHeadDuck/ReadHeadDuck.hpp"
#include "Ducks/DecoyDuck/DecoyDuck.hpp"
#include "Ducks/MallardDuck/MallardDuck.hpp"

int main()
{
    {
        int counter = 0;

        auto duck = ReadHeadDuck([&counter](){
            ++counter;
            std::cout << "Flying with wings, number: " << counter << std::endl;
        });

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
        int counter = 0;

        auto duck = MallardDuck([&counter](){
            ++counter;
            std::cout << "Flying with wings, number: " << counter << std::endl;
        });

        duck.Fly();
        duck.Dance(100);
        duck.Fly();

        duck.Fly();
        duck.Fly();
        duck.Fly();
        duck.Display();
    }

    return 0;
}

#include "Ducks/ReadHeadDuck/ReadHeadDuck.hpp"
#include "Ducks/DecoyDuck/DecoyDuck.hpp"
#include "Ducks/MallardDuck/MallardDuck.hpp"

int main()
{
    {
        auto duck = ReadHeadDuck();

        duck.Fly();
        duck.Dance(20);
    }

    {
        auto duck = DecoyDuck();

        duck.Fly();
        duck.Dance(30);
    }

    {
        auto duck = MallardDuck();

        duck.Fly();
        duck.Dance(100);
    }

    return 0;
}

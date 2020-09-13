#include "Ducks/ReadHeadDuck/ReadHeadDuck.hpp"
#include "Ducks/DecoyDuck/DecoyDuck.hpp"
#include "Ducks/MallardDuck/MallardDuck.hpp"
#include "FlyCounter/NoFlyCounter/NoFlyCounter.hpp"

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
        duck.Dance(10000);
    }

    {
        auto duck = MallardDuck();

        duck.Fly();
        duck.Dance(100);
        duck.SetFlyCounter(std::make_unique<NoFlyCounter>());
        duck.Fly();
    }

    return 0;
}

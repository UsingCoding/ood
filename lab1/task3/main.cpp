#include "Ducks/ReadHeadDuck/ReadHeadDuck.hpp"
#include "Ducks/DecoyDuck/DecoyDuck.hpp"
#include "Ducks/MallardDuck/MallardDuck.hpp"

int main(int argc, char const *argv[])
{
    {
        auto duck = ReadHeadDuck();

        duck.fly();
        duck.dance();
    }

    {
        auto duck = DecoyDuck();

        duck.fly();
        duck.dance();
    }

    {
        auto duck = MallardDuck();

        duck.fly();
        duck.dance();
    }

    return 0;
}

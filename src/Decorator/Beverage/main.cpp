#include <memory>
#include "Beverages/Latte/Latte.hpp"
#include "Condiments/Condiments.hpp"

int main()
{
    auto latte = std::make_unique<Latte>();

    auto lemon = std::make_unique<Lemon>(std::move(latte), 3);

    return 0;
}
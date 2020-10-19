#include <memory>
#include <iostream>
#include "Beverages/Latte/Latte.hpp"
#include "Condiments/Cream.hpp"
#include "Condiments/Chocolate.hpp"
#include "Condiments/ChocolateLiquor.hpp"
#include "Condiments/WalnutLiquor.hpp"
#include "Beverages/Cappuccino/Cappuccino.hpp"
#include "Beverages/Cappuccino/DoubleCappuccino.hpp"
#include "Beverages/Tea/BergamotTea.hpp"
#include "Beverages/Tea/CeylonTea.hpp"
#include "Beverages/Tea/GreenTea.hpp"
#include "Beverages/Tea/YellowTea.hpp"

void DialogWithUser()
{
    std::cout << "Type 1 for cappuccino or 2 for double cappuccino, 3 for Bergamot tea, 4 Ceylon tea, 5 Green Tea, 6 Yellow tea" << std::endl;
    int beverageChoice;
    std::cin >> beverageChoice;

    std::unique_ptr<IBeverage> beverage;

    if (beverageChoice == 1)
    {
        beverage = std::make_unique<Cappuccino>();
    }
    else if (beverageChoice == 2)
    {
        beverage = std::make_unique<DoubleCappuccino>();
    }
    else if (beverageChoice == 3)
    {
        beverage = std::make_unique<BergamotTea>();
    }
    else if (beverageChoice == 4)
    {
        beverage = std::make_unique<CeylonTea>();
    }
    else if (beverageChoice == 5)
    {
        beverage = std::make_unique<GreenTea>();
    }
    else if (beverageChoice == 6)
    {
        beverage = std::make_unique<YellowTea>();
    }
    else
    {
        return;
    }

    int condimentChoice;
    for (;;)
    {
        std::cout << "1 - Cream, 2 - Chocolate, 3 - Liquor, 0 - Checkout" << std::endl;
        std::cin >> condimentChoice;

        if (condimentChoice == 1)
        {
            beverage = std::make_unique<Cream>(move(beverage));
        }
        else if (condimentChoice == 2)
        {
            std::cout << "Enter chocolate slices count" << std::endl;
            int slicesCount;
            std::cin >> slicesCount;

            try
            {
                beverage = std::make_unique<Chocolate>(move(beverage), slicesCount);
            }
            catch (const std::logic_error & error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (condimentChoice == 3)
        {
            std::cout << "Enter liquor: 1 - chocolate, 2 - walnut" << std::endl;
            int liquorChoice;
            std::cin >> liquorChoice;

            if (liquorChoice == 1)
            {
                beverage = std::make_unique<ChocolateLiquor>(std::move(beverage));
            }
            else if (liquorChoice == 2)
            {
                beverage = std::make_unique<WalnutLiquor>(std::move(beverage));
            }
            else
            {
                std::cout << "Skipping liquor choice. Setted incorrect param";
            }
        }
        else if (condimentChoice == 0)
        {
            break;
        }
        else
        {
            return;
        }
    }



    std::cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << std::endl;
}

int main()
{
    DialogWithUser();

    return 0;
}
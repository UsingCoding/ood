#include <iostream>
#include "SoldOutState.hpp"

using namespace GumBallWithState;

SoldOutState::SoldOutState(IGumBallMachine &gumballMachine) : m_gumballMachine(gumballMachine) {}

void GumBallWithState::SoldOutState::InsertQuarter()
{
    std::cout << "You can't insert a quarter, the machine is sold out\n";
}

void SoldOutState::EjectQuarter()
{
    if (m_gumballMachine.GetCoinsCount() == 0)
    {
        std::cout << "You can't eject, you haven't inserted a quarter yet\n";
        return;
    }

    std::cout << "Quarter(s) returned: " << m_gumballMachine.GetCoinsCount() << '\n';

    m_gumballMachine.ResetCoins();
}

void SoldOutState::TurnCrank()
{
    std::cout << "You turned but there's no gumballs\n";

}

void SoldOutState::Dispense()
{
    std::cout << "No gumball dispensed\n";
}

std::string SoldOutState::ToString() const
{
    return "sold out";
}
#include <iostream>
#include "NoQuarterState.hpp"

GumBallWithState::NoQuarterState::NoQuarterState(IGumBallMachine &gumballMachine) : m_gumballMachine(gumballMachine) {}

void GumBallWithState::NoQuarterState::InsertQuarter()
{
    std::cout << "You inserted a quarter\n";
    m_gumballMachine.SetHasQuarterState();
}

void GumBallWithState::NoQuarterState::EjectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}

void GumBallWithState::NoQuarterState::TurnCrank()
{
    std::cout << "You turned but there's no quarter\n";
}

void GumBallWithState::NoQuarterState::Dispense()
{
    std::cout << "You need to pay first\n";
}

std::string GumBallWithState::NoQuarterState::ToString() const
{
    return "waiting for quarter";
}

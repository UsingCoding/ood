#include <iostream>
#include "NoQuarterState.hpp"

GumBallWithDynamicState::NoQuarterState::NoQuarterState(IGumBallMachine &gumballMachine) : m_gumballMachine(gumballMachine) {}

void GumBallWithDynamicState::NoQuarterState::InsertQuarter()
{
    std::cout << "You inserted a quarter\n";
    m_gumballMachine.SetHasQuarterState();
}

void GumBallWithDynamicState::NoQuarterState::EjectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}

void GumBallWithDynamicState::NoQuarterState::TurnCrank()
{
    std::cout << "You turned but there's no quarter\n";
}

void GumBallWithDynamicState::NoQuarterState::Dispense()
{
    std::cout << "You need to pay first\n";
}

std::string GumBallWithDynamicState::NoQuarterState::ToString() const
{
    return "waiting for quarter";
}

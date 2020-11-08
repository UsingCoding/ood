#include <iostream>
#include "HasQuarterState.hpp"

GumBallWithDynamicState::HasQuarterState::HasQuarterState(IGumBallMachine &gumballMachine) : m_gumballMachine(gumballMachine) {}

void GumBallWithDynamicState::HasQuarterState::InsertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void GumBallWithDynamicState::HasQuarterState::EjectQuarter()
{
    std::cout << "Quarter returned\n";
    m_gumballMachine.SetNoQuarterState();
}

void GumBallWithDynamicState::HasQuarterState::TurnCrank()
{
    std::cout << "You turned...\n";
    m_gumballMachine.SetSoldState();
}

void GumBallWithDynamicState::HasQuarterState::Dispense()
{
    std::cout << "No gumball dispensed\n";
}

std::string GumBallWithDynamicState::HasQuarterState::ToString() const
{
    return "waiting for turn of crank";
}

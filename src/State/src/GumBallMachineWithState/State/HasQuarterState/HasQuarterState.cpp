#include <iostream>
#include "HasQuarterState.hpp"

GumBallWithState::HasQuarterState::HasQuarterState(IGumBallMachine &gumballMachine) : m_gumballMachine(gumballMachine) {}

void GumBallWithState::HasQuarterState::InsertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void GumBallWithState::HasQuarterState::EjectQuarter()
{
    std::cout << "Quarter returned\n";
    m_gumballMachine.SetNoQuarterState();
}

void GumBallWithState::HasQuarterState::TurnCrank()
{
    std::cout << "You turned...\n";
    m_gumballMachine.SetSoldState();
}

void GumBallWithState::HasQuarterState::Dispense()
{
    std::cout << "No gumball dispensed\n";
}

std::string GumBallWithState::HasQuarterState::ToString() const
{
    return "waiting for turn of crank";
}

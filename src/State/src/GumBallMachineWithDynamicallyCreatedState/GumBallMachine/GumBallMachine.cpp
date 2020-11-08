#include <iostream>
#include <Strings.hpp>
#include "GumBallMachine.hpp"
#include "../State/SoldOutState/SoldOutState.hpp"
#include "../State/NoQuarterState/NoQuarterState.hpp"
#include "../State/SoldState/SoldState.hpp"
#include "../State/HasQuarterState/HasQuarterState.hpp"

GumBallWithDynamicState::GumBallMachine::GumBallMachine(unsigned int count) : m_count(count)
{
    if (m_count > 0)
    {
        SetNoQuarterState();
    }
    else
    {
        SetSoldOutState();
    }
}

void GumBallWithDynamicState::GumBallMachine::ReleaseBall()
{
    if (m_count != 0)
    {
        std::cout << "A gumball comes rolling out the slot...\n";
        --m_count;
    }
}

unsigned int GumBallWithDynamicState::GumBallMachine::GetBallCount() const
{
    return m_count;
}

void GumBallWithDynamicState::GumBallMachine::SetSoldOutState()
{
    m_currentState.reset(new SoldOutState(*this));
}

void GumBallWithDynamicState::GumBallMachine::SetNoQuarterState()
{
    m_currentState.reset(new NoQuarterState(*this));
}

void GumBallWithDynamicState::GumBallMachine::SetSoldState()
{
    m_currentState.reset(new SoldState(*this));
}

void GumBallWithDynamicState::GumBallMachine::SetHasQuarterState()
{
    m_currentState.reset(new HasQuarterState(*this));
}

void GumBallWithDynamicState::GumBallMachine::EjectQuarter()
{
    m_currentState->EjectQuarter();
}

void GumBallWithDynamicState::GumBallMachine::InsertQuarter()
{
    m_currentState->InsertQuarter();
}

void GumBallWithDynamicState::GumBallMachine::TurnCrank()
{
    m_currentState->TurnCrank();
    m_currentState->Dispense();
}

std::string GumBallWithDynamicState::GumBallMachine::ToString() const
{
    return Strings::Concatenator() <<
        "Mighty Gumball, Inc.\n" <<
        "C++-enabled Standing Gumball Model #2016\n" <<
        "Inventory: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << '\n' <<
        "Machine is " << m_currentState->ToString();
}

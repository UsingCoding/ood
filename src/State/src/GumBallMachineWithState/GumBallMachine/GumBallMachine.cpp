#include <iostream>
#include <Strings.hpp>
#include "GumBallMachine.hpp"

void GumBallWithState::GumBallMachine::ReleaseBall()
{
    if (m_count != 0)
    {
        std::cout << "A gumball comes rolling out the slot...\n";
        --m_count;
    }
}

unsigned int GumBallWithState::GumBallMachine::GetBallCount() const
{
    return m_count;
}

void GumBallWithState::GumBallMachine::SetSoldOutState()
{
    m_state = &m_soldOutState;
}

void GumBallWithState::GumBallMachine::SetNoQuarterState()
{
    m_state = &m_noQuarterState;
}

void GumBallWithState::GumBallMachine::SetSoldState()
{
    m_state = &m_soldState;
}

void GumBallWithState::GumBallMachine::SetHasQuarterState()
{
    m_state = &m_hasQuarterState;
}

void GumBallWithState::GumBallMachine::EjectQuarter()
{
    m_state->EjectQuarter();
}

void GumBallWithState::GumBallMachine::InsertQuarter()
{
    m_state->InsertQuarter();
}

void GumBallWithState::GumBallMachine::TurnCrank()
{
    m_state->TurnCrank();
    m_state->Dispense();
}

std::string GumBallWithState::GumBallMachine::ToString() const
{
    return Strings::Concatenator() <<
        "Mighty Gumball, Inc.\n" <<
        "C++-enabled Standing Gumball Model #2016\n" <<
        "Inventory: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << '\n' <<
        "Coins: " << m_coinsCount << '\n' <<
        "Machine is " << m_state->ToString();
}

GumBallWithState::GumBallMachine::GumBallMachine(unsigned int count)
        : m_soldState(*this)
        , m_soldOutState(*this)
        , m_noQuarterState(*this)
        , m_hasQuarterState(*this)
        , m_state(&m_soldOutState)
        , m_count(count)
{
    if (m_count > 0)
    {
        m_state = &m_noQuarterState;
    }
}

unsigned int GumBallWithState::GumBallMachine::GetCoinsCount() const
{
    return m_coinsCount;
}

void GumBallWithState::GumBallMachine::AddCoin()
{
    m_coinsCount++;
}

void GumBallWithState::GumBallMachine::ResetCoins()
{
    m_coinsCount = 0;
}

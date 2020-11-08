#include <Strings.hpp>
#include <iostream>
#include "GumBallMachineWithStaticState.hpp"

void GumBallWithState::GumBallMachineWithStaticState::ReleaseBall()
{
    if (m_count != 0)
    {
        std::cout << "A gumball comes rolling out the slot...\n";
        --m_count;
    }
}

unsigned int GumBallWithState::GumBallMachineWithStaticState::GetBallCount() const
{
    return m_count;
}

void GumBallWithState::GumBallMachineWithStaticState::SetSoldOutState()
{
    m_state = &m_soldOutState;
}

void GumBallWithState::GumBallMachineWithStaticState::SetNoQuarterState()
{
    m_state = &m_noQuarterState;
}

void GumBallWithState::GumBallMachineWithStaticState::SetSoldState()
{
    m_state = &m_soldState;
}

void GumBallWithState::GumBallMachineWithStaticState::SetHasQuarterState()
{
    m_state = &m_hasQuarterState;
}

void GumBallWithState::GumBallMachineWithStaticState::EjectQuarter()
{
    m_state->EjectQuarter();
}

void GumBallWithState::GumBallMachineWithStaticState::InsertQuarter()
{
    m_state->InsertQuarter();
}

void GumBallWithState::GumBallMachineWithStaticState::TurnCrank()
{
    m_state->TurnCrank();
    m_state->Dispense();
}

std::string GumBallWithState::GumBallMachineWithStaticState::ToString() const
{
    return Strings::Concatenator() <<
                                   "Mighty Gumball, Inc.\n" <<
                                   "C++-enabled Standing Gumball Model #2016\n" <<
                                   "Inventory: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << '\n' <<
                                   "Coins: " << m_coinsCount << '\n' <<
                                   "Machine is " << m_state->ToString();
}

GumBallWithState::GumBallMachineWithStaticState::GumBallMachineWithStaticState(unsigned int count)
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

unsigned int GumBallWithState::GumBallMachineWithStaticState::GetCoinsCount() const
{
    return m_coinsCount;
}

void GumBallWithState::GumBallMachineWithStaticState::AddCoin()
{
    m_coinsCount++;
}

void GumBallWithState::GumBallMachineWithStaticState::ResetCoins()
{
    m_coinsCount = 0;
}

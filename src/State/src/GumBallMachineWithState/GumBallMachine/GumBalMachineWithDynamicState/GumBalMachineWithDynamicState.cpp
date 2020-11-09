#include <iostream>
#include <Strings.hpp>
#include "GumBalMachineWithDynamicState.hpp"
#include "../../State/SoldOutState/SoldOutState.hpp"
#include "../../State/NoQuarterState/NoQuarterState.hpp"
#include "../../State/SoldState/SoldState.hpp"
#include "../../State/HasQuarterState/HasQuarterState.hpp"

using namespace GumBallWithState;

GumBallWithState::GumBalMachineWithDynamicState::GumBalMachineWithDynamicState(unsigned int count): m_count(count)
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

void GumBallWithState::GumBalMachineWithDynamicState::ReleaseBall()
{
    if (m_count != 0)
    {
        std::cout << "A gumball comes rolling out the slot...\n";

        if (m_coinsCount > m_count)
        {
            m_count = 0;
        }
        else
        {
            m_count -= m_coinsCount;
        }
    }
}

unsigned int GumBallWithState::GumBalMachineWithDynamicState::GetBallCount() const
{
    return m_count;
}

void GumBallWithState::GumBalMachineWithDynamicState::SetSoldOutState()
{
    m_currentState.reset(new SoldOutState(*this));
}

void GumBallWithState::GumBalMachineWithDynamicState::SetNoQuarterState()
{
    m_currentState.reset(new NoQuarterState(*this));
}

void GumBallWithState::GumBalMachineWithDynamicState::SetSoldState()
{
    m_currentState.reset(new SoldState(*this));
}

void GumBallWithState::GumBalMachineWithDynamicState::SetHasQuarterState()
{
    m_currentState.reset(new HasQuarterState(*this));
}

void GumBallWithState::GumBalMachineWithDynamicState::EjectQuarter()
{
    m_currentState->EjectQuarter();
}

void GumBallWithState::GumBalMachineWithDynamicState::InsertQuarter()
{
    m_currentState->InsertQuarter();
}

void GumBallWithState::GumBalMachineWithDynamicState::TurnCrank()
{
    m_currentState->TurnCrank();
    m_currentState->Dispense();
}

std::string GumBallWithState::GumBalMachineWithDynamicState::ToString() const
{
    return Strings::Concatenator() <<
        "Mighty Gumball, Inc.\n" <<
        "C++-enabled Standing Gumball Model #2016\n" <<
        "Inventory: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << '\n' <<
        "Coins: " << m_coinsCount << '\n' <<
        "Machine is " << m_currentState->ToString();
}

unsigned int GumBallWithState::GumBalMachineWithDynamicState::GetCoinsCount() const
{
    return m_coinsCount;
}

void GumBallWithState::GumBalMachineWithDynamicState::AddCoin()
{
    m_coinsCount++;
}

void GumBallWithState::GumBalMachineWithDynamicState::ResetCoins()
{
    m_coinsCount = 0;
}

void GumBalMachineWithDynamicState::SpendCoin()
{
    m_coinsCount--;
}

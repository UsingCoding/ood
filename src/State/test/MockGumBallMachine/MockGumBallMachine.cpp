#include "MockGumBallMachine.hpp"

State::MockGumBallMachine::MockGumBallMachine(unsigned int count)
        : m_soldState(*this)
        , m_soldOutState(*this)
        , m_noQuarterState(*this)
        , m_hasQuarterState(*this)
        , m_state(&m_soldOutState)
        , m_mockState(MOCK_STATE::SOLD_OUT)
        , m_count(count)
{
    if (m_count > 0)
    {
        m_state = &m_noQuarterState;
        m_mockState = MOCK_STATE::NO_QUARTER;
    }
}

void State::MockGumBallMachine::ReleaseBall()
{
    if (m_count != 0)
    {
        --m_count;
    }
}

unsigned int State::MockGumBallMachine::GetBallCount() const
{
    return m_count;
}

void State::MockGumBallMachine::SetSoldOutState()
{
    m_state = &m_soldOutState;
    m_mockState = MOCK_STATE::SOLD_OUT;
}

void State::MockGumBallMachine::SetNoQuarterState()
{
    m_state = &m_noQuarterState;
    m_mockState = MOCK_STATE::NO_QUARTER;
}

void State::MockGumBallMachine::SetSoldState()
{
    m_state = &m_soldState;
    m_mockState = MOCK_STATE::SOLD;
}

void State::MockGumBallMachine::SetHasQuarterState()
{
    m_state = &m_hasQuarterState;
    m_mockState = MOCK_STATE::HAS_QUARTER;
}

State::MockGumBallMachine::MOCK_STATE State::MockGumBallMachine::GetMockState() const
{
    return m_mockState;
}

IState *State::MockGumBallMachine::GetState() const
{
    return m_state;
}

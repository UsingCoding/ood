#pragma once

#include "../../src/GumBallMachineWithState/GumBallMachine/IGumBallMachine.hpp"
#include "../../src/GumBallMachineWithState/State/SoldState/SoldState.hpp"
#include "../../src/GumBallMachineWithState/State/SoldOutState/SoldOutState.hpp"
#include "../../src/GumBallMachineWithState/State/NoQuarterState/NoQuarterState.hpp"
#include "../../src/GumBallMachineWithState/State/HasQuarterState/HasQuarterState.hpp"

namespace State
{
    class MockGumBallMachine : public GumBallWithState::IGumBallMachine
    {
    public:
        enum class MOCK_STATE
        {
            HAS_QUARTER,
            NO_QUARTER,
            SOLD_OUT,
            SOLD
        };

        MockGumBallMachine(unsigned int count);

        void ReleaseBall() override;

        unsigned int GetBallCount() const override;

        void SetSoldOutState() override;

        void SetNoQuarterState() override;

        void SetSoldState() override;

        void SetHasQuarterState() override;

        void AddCoin() override;

        unsigned int GetCoinsCount() const override;

        void ResetCoins() override;

        MOCK_STATE GetMockState() const;

        IState * GetState() const;

    private:
        unsigned m_count;
        unsigned m_coinsCount = 0;
        MOCK_STATE m_mockState;
        GumBallWithState::SoldState m_soldState;
        GumBallWithState::SoldOutState m_soldOutState;
        GumBallWithState::NoQuarterState m_noQuarterState;
        GumBallWithState::HasQuarterState m_hasQuarterState;
        IState * m_state;
    };
}

#pragma once

#include "IGumBallMachine.hpp"
#include "../State/SoldState/SoldState.hpp"
#include "../State/SoldOutState/SoldOutState.hpp"
#include "../State/NoQuarterState/NoQuarterState.hpp"
#include "../State/HasQuarterState/HasQuarterState.hpp"

namespace GumBallWithState
{
    class GumBallMachine : public IGumBallMachine
    {
    public:
        GumBallMachine(unsigned int count);

        void EjectQuarter();
        void InsertQuarter();
        void TurnCrank();
        std::string ToString() const;

    private:
        void ReleaseBall() override;

        unsigned int GetBallCount() const override;

        void SetSoldOutState() override;

        unsigned int GetCoinsCount() const override;

        void AddCoin() override;

        void ResetCoins() override;

        void SetNoQuarterState() override;

        void SetSoldState() override;

        void SetHasQuarterState() override;
    private:
        unsigned m_count = 0;
        unsigned m_coinsCount = 0;
        SoldState m_soldState;
        SoldOutState m_soldOutState;
        NoQuarterState m_noQuarterState;
        HasQuarterState m_hasQuarterState;
        IState * m_state;
    };
}

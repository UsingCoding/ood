#pragma once

#include <memory>
#include "../IGumBallMachine.hpp"
#include "../../State/IState.hpp"

namespace GumBallWithState
{
    class GumBalMachineWithDynamicState : private IGumBallMachine
    {
    public:
        GumBalMachineWithDynamicState(unsigned int count);

        void EjectQuarter();
        void InsertQuarter();
        void TurnCrank();
        std::string ToString() const;

    private:
        void ReleaseBall() override;

        unsigned int GetBallCount() const override;

        void SetSoldOutState() override;

        void SetNoQuarterState() override;

        void SetSoldState() override;

        void SetHasQuarterState() override;

        void AddCoin() override;

        void SpendCoin() override;

        unsigned int GetCoinsCount() const override;

        void ResetCoins() override;

    private:
        unsigned m_count = 0;
        unsigned m_coinsCount = 0;
        std::unique_ptr<IState> m_currentState;
    };
}

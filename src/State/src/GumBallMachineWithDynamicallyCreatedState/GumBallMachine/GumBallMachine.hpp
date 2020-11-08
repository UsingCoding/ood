#pragma once

#include <memory>
#include "IGumBallMachine.hpp"
#include "../State/IState.hpp"

namespace GumBallWithDynamicState
{
    class GumBallMachine : private IGumBallMachine
    {
    public:
        void EjectQuarter();
        void InsertQuarter();
        void TurnCrank();
        std::string ToString() const;
    private:
        GumBallMachine(unsigned int count);

        void ReleaseBall() override;

        unsigned int GetBallCount() const override;

        void SetSoldOutState() override;

        void SetNoQuarterState() override;

        void SetSoldState() override;

        void SetHasQuarterState() override;

    private:
        unsigned m_count;
        std::unique_ptr<IState> m_currentState;
    };
}

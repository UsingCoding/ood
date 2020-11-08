#pragma once

#include "../IState.hpp"
#include "../../GumBallMachine/IGumBallMachine.hpp"

namespace GumBallWithDynamicState
{
    class NoQuarterState : public IState
    {
    public:
        NoQuarterState(IGumBallMachine &gumballMachine);

        void InsertQuarter() override;

        void EjectQuarter() override;

        void TurnCrank() override;

        void Dispense() override;

        std::string ToString() const override;

    private:
        IGumBallMachine & m_gumballMachine;
    };
}


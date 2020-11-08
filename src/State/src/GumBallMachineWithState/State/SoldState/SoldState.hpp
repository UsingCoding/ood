#pragma once

#include "../IState.hpp"
#include "../../GumBallMachine/IGumBallMachine.hpp"

namespace GumBallWithState
{
    class SoldState : public IState
    {
    public:
        SoldState(IGumBallMachine &gumballMachine);

        void InsertQuarter() override;

        void EjectQuarter() override;

        void TurnCrank() override;

        void Dispense() override;

        std::string ToString() const override;

    private:
        IGumBallMachine & m_gumballMachine;
    };
}


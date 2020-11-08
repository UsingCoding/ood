#pragma once

namespace GumBallWithState
{
    class IGumBallMachine
    {
    public:
        virtual void ReleaseBall() = 0;
        virtual unsigned GetBallCount() const = 0;

        virtual void SetSoldOutState() = 0;
        virtual void SetNoQuarterState() = 0;
        virtual void SetSoldState() = 0;
        virtual void SetHasQuarterState() = 0;

        virtual void AddCoin() = 0;
        virtual unsigned GetCoinsCount() const = 0;
        virtual void ResetCoins() = 0;

        virtual ~IGumBallMachine() = default;
    };
}
#pragma once
#include <memory>
#include "../../DanceBehavior/IDanceBehavior.hpp"
#include "../../FlyBehavior/IFlyBehavior.hpp"
#include "../../FlyCounter/IFlyCounter.hpp"

class Duck
{
public:
    Duck(std::unique_ptr<IFlyBehavior> && flyBehavior, std::unique_ptr<IDanceBehavior> && danceBehavior, std::unique_ptr<IFlyCounter> && flyCounter);
    void Fly();
    void Dance(int speed);
    void SetFlyCounter(std::unique_ptr<IFlyCounter> && flyCounter);

private:
    std::unique_ptr<IFlyBehavior> m_flyBehavior;
    std::unique_ptr<IDanceBehavior> m_danceBehavior;
    std::unique_ptr<IFlyCounter> m_flyCounter;
};

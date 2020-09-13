#pragma once
#include <memory>
#include "../../DanceBehavior/IDanceBehavior.hpp"
#include "../../FlyBehavior/IFlyBehavior.hpp"

class Duck
{
public:
    Duck(std::unique_ptr<IFlyBehavior> && flyBehavior, std::unique_ptr<IDanceBehavior> && danceBehavior);
    void Fly();
    void Dance(int speed);

private:
    std::unique_ptr<IFlyBehavior> m_flyBehavior;
    std::unique_ptr<IDanceBehavior> m_danceBehavior;
};

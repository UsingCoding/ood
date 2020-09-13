#include "Duck.hpp"
#include "../../FlyCounter/NoFlyCounter/NoFlyCounter.hpp"

#include <memory>

Duck::Duck(
        std::unique_ptr<IFlyBehavior> && flyBehavior,
        std::unique_ptr<IDanceBehavior> && danceBehavior,
        std::unique_ptr<IFlyCounter> && flyCounter
        ):
    m_flyBehavior(std::move(flyBehavior)),
    m_danceBehavior(std::move(danceBehavior)),
    m_flyCounter(std::move(flyCounter))
{

}

void Duck::SetFlyCounter(std::unique_ptr<IFlyCounter> && flyCounter)
{
    m_flyCounter = std::move(flyCounter);
}

void Duck::Fly()
{
    m_flyBehavior->Fly();
    m_flyCounter->Add();
}

void Duck::Dance(int speed)
{
    m_danceBehavior->Dance(speed);
}


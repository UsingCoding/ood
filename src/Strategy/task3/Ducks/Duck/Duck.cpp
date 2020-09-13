#include "Duck.hpp"

#include <memory>

Duck::Duck(std::function<void(void)> && flyBehavior, std::function<void(int)> && danceBehavior, std::function<void(void)> && flyCounter):
    m_flyBehavior(std::move(flyBehavior)),
    m_danceBehavior(std::move(danceBehavior)),
    m_flyCounter(std::move(flyCounter))
{

}

void Duck::SetFlyCounter(std::function<void(void)> && flyCounter)
{
    m_flyCounter = std::move(flyCounter);
}

void Duck::Fly()
{
    m_flyBehavior();
    m_flyCounter();
}

void Duck::Dance(int speed)
{
    m_danceBehavior(speed);
}


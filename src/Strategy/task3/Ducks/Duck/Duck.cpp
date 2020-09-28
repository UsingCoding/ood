#include "Duck.hpp"

#include <memory>

Duck::Duck(std::function<void(void)> && flyBehavior, std::function<void(int)> && danceBehavior):
    m_flyBehavior(std::move(flyBehavior)),
    m_danceBehavior(std::move(danceBehavior))
{

}

void Duck::Fly()
{
    m_flyBehavior();
}

void Duck::Dance(int speed)
{
    m_danceBehavior(speed);
}


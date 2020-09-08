#include "Duck.hpp"

Duck::Duck(std::function<void(void)> && flyBehavior, std::function<void(void)> && danceBehavior):
    m_flyBehavior(flyBehavior), m_danceBehavior(danceBehavior)
{

}

void Duck::fly()
{
    m_flyBehavior();
}

void Duck::dance()
{
    m_danceBehavior();
}

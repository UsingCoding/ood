#include "Duck.hpp"

#include <memory>

Duck::Duck(std::unique_ptr<IFlyBehavior> && flyBehavior, std::unique_ptr<IDanceBehavior> && danceBehavior):
    m_flyBehavior(std::move(flyBehavior)), m_danceBehavior(std::move(danceBehavior))
{

}

void Duck::fly()
{
    m_flyBehavior->fly();
}

void Duck::dance()
{
    m_danceBehavior->dance();
}

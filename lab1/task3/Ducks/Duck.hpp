#pragma once
#include <memory>
#include <functional>

class Duck
{
public:
    Duck(std::function<void(void)> && flyBehavior, std::function<void(void)> && danceBehavior);
    void fly();
    void dance();

private:
    std::function<void(void)> m_flyBehavior;
    std::function<void(void)> m_danceBehavior;
};

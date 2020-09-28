#pragma once
#include <memory>
#include <functional>

class Duck
{
public:
    Duck(std::function<void(void)> && flyBehavior, std::function<void(int)> && danceBehavior);
    void Fly();
    void Dance(int speed);
    virtual void Display() const = 0;

private:
    std::function<void(void)> m_flyBehavior;
    std::function<void(int)> m_danceBehavior;
    std::function<void(void)> m_flyCounter;
};

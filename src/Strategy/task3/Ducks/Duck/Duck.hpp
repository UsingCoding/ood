#pragma once
#include <memory>
#include <functional>

class Duck
{
public:
    Duck(std::function<void(void)> && flyBehavior, std::function<void(int)> && danceBehavior, std::function<void(void)> && flyCounter);
    void Fly();
    void Dance(int speed);
    void SetFlyCounter(std::function<void(void)> && flyCounter);

private:
    std::function<void(void)> m_flyBehavior;
    std::function<void(int)> m_danceBehavior;
    std::function<void(void)> m_flyCounter;
};

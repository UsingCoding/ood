#pragma once

#include <memory>
#include <stack>
#include "../../Observer/Observer/IObserver.hpp"
#include "../Observerable/MockObservable.hpp"


class MockObserver: public IObserver<MockInfo>
{
public:
    MockObserver(const std::string && name, std::shared_ptr<std::stack<std::string>> callStack):
        m_name(std::move(name)), m_callStack(callStack) {}

    void Update(const MockInfo &data) override;
private:
    std::string m_name;
    std::shared_ptr<std::stack<std::string>> m_callStack;
};

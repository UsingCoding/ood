#include "MockObserver.hpp"

void PriorityTest::MockObserver::Update(const MockInfo & data)
{
    m_callStack->push(m_name);
}

#include "MockObserver.hpp"

void MockObserver::Update(const MockInfo & data)
{
    m_callStack->push(m_name);
}

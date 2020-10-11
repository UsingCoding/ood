#pragma once

#include "../../../Observer/Observer/IObserver.hpp"
#include "../Observable/MockObservable.hpp"

namespace SafeObserversRemoving
{
    class MockObserver : public IObserver<MockInfo>
    {
    public:
        MockObserver(bool deleteFromObservable, SafeObserversRemoving::MockObservable & observable):
                m_deleteFromObservable(deleteFromObservable), m_observable(observable) {}

        void Update(const MockInfo &data) override
        {
            if (m_deleteFromObservable)
            {
                m_observable.RemoveObserver(MockEventType::MOCK_EVENT_TYPE, *this);
            }
        }

    private:
        bool m_deleteFromObservable;
        SafeObserversRemoving::MockObservable & m_observable;
    };
}

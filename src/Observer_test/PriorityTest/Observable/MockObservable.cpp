#include "MockObservable.hpp"

std::map<PriorityTest::MockEventType, PriorityTest::MockInfo> PriorityTest::MockObservable::GetChangedData() const
{
    return std::map<PriorityTest::MockEventType, PriorityTest::MockInfo>{
        std::make_pair<PriorityTest::MockEventType, PriorityTest::MockInfo>(MockEventType::MOCK_EVENT_TYPE, MockInfo())
    };
}

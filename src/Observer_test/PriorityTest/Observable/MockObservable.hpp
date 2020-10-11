#pragma once

#include "../../../Observer/Observer/CObserverable.hpp"

namespace PriorityTest {
    enum MockEventType
    {
        MOCK_EVENT_TYPE
    };

    struct MockInfo
    {

    };

    class MockObservable: public CObservable<MockInfo, MockEventType>
    {
    protected:
        std::map<MockEventType, MockInfo> GetChangedData() const override;
    };
}

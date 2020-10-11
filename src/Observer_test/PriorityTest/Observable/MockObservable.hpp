#pragma once

#include "../../../Observer/Observer/CObserverable.hpp"

namespace PriorityTest {
    struct MockInfo
    {

    };

    class MockObservable: public CObservable<MockInfo>
    {
    protected:
        MockInfo GetChangedData() const override;
    };
}

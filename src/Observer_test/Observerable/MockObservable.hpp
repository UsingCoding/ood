#pragma once

#include "../../Observer/Observer/CObserverable.hpp"

struct MockInfo
{

};

class MockObservable: public CObservable<MockInfo>
{
protected:
    MockInfo GetChangedData() const override;
};

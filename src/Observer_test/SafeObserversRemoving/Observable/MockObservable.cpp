#include "MockObservable.hpp"

std::map<SafeObserversRemoving::MockEventType, SafeObserversRemoving::MockInfo> SafeObserversRemoving::MockObservable::GetChangedData() const {
    return std::map<SafeObserversRemoving::MockEventType, SafeObserversRemoving::MockInfo>{
            std::make_pair<SafeObserversRemoving::MockEventType, SafeObserversRemoving::MockInfo>(MockEventType::MOCK_EVENT_TYPE, MockInfo())
    };
}

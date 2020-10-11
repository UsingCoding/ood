#pragma once

#include "IObserver.hpp"

template <class T, class Y>
class IObservable
{
public:
    virtual ~IObservable() = default;
    virtual void RegisterObserver(Y eventType, IObserver<T> & observer, int priority = 0) = 0;
    virtual void NotifyObservers() = 0;
    virtual void RemoveObserver(Y eventType, IObserver<T> & observer) = 0;
};
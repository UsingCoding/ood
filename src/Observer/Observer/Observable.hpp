#pragma once

#include "IObserver.hpp"

template <typename T>
class IObservable
{
public:
    virtual ~IObservable() = default;
    virtual void RegisterObserver(int priority, IObserver<T> & observer) = 0;
    virtual void NotifyObservers() = 0;
    virtual void RemoveObserver(IObserver<T> & observer) = 0;
};
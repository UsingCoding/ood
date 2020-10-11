#pragma once

#include <map>
#include <iostream>
#include "Observable.hpp"

template <class T, class Y>
class CObservable : public IObservable<T, Y>
{
public:
    typedef IObserver<T> ObserverType;

    struct Record
    {
        Y m_eventType;
        ObserverType* m_observer;
    };

    void RegisterObserver(Y eventType, IObserver<T> & observer, int priority = 0) override
    {
        m_observers.insert(std::make_pair<int, Record>(std::move(priority), Record{eventType, &observer}));
    }

    void NotifyObservers() override
    {
        std::map<Y, T> data = GetChangedData();
        for (auto it = m_observers.rbegin(); it != m_observers.rend(); ++it)
        {
            if (data.find(it->second.m_eventType) != data.end())
            {
                it->second.m_observer->Update(data.at(it->second.m_eventType));
            }
        }
    }

    void RemoveObserver(Y eventType, ObserverType & observer) override
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); it++)
        {
            if (it->second.m_eventType == eventType && it->second.m_observer == &observer)
            {
                m_observers.erase(it);
            }
        }
    }

protected:
    virtual std::map<Y, T> GetChangedData() const = 0;

private:
    std::multimap<int, Record> m_observers;
};
#pragma once

#include <set>
#include <map>
#include <iostream>
#include "Observable.hpp"

template <class T>
class CObservable : public IObservable<T>
{
public:
    typedef IObserver<T> ObserverType;

    void RegisterObserver(int priority, IObserver<T> & observer) override
    {
        m_observers.insert(std::make_pair<int, ObserverType *>(std::move(priority), &observer));
    }

    void NotifyObservers() override
    {
        T data = GetChangedData();
        for (auto it = m_observers.rbegin(); it != m_observers.rend(); ++it)
        {
            it->second->Update(data);
        }
    }

    void RemoveObserver(ObserverType & observer) override
    {
        typename std::multimap<int, ObserverType *>::iterator iteratorToRemove = m_observers.end();
        for (auto it = m_observers.begin(); it != m_observers.end(); it++)
        {
            if (it->second == &observer)
            {
                iteratorToRemove = it;
            }
        }

        if (iteratorToRemove == m_observers.end())
        {
            return;
        }

        m_observers.erase(iteratorToRemove);
    }

protected:
    virtual T GetChangedData()const = 0;

private:
    std::multimap<int, ObserverType *> m_observers;
};
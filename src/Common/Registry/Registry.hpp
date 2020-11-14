#pragma once

#include <memory>
#include <map>

template<class Id, class Service>
class Registry
{
public:
    void Register(const Id &id, std::unique_ptr<Service> commandHandler)
    {
        if (m_services.find(id) != m_services.end())
        {
            throw std::logic_error("Service with the same id already registered, id: " + id);
        }

        m_services.insert(std::make_pair(id, std::move(commandHandler)));
    }

    std::unique_ptr<Service> &Get(const Id &id) const
    {
        auto iterator = m_services.find(id);

        if (iterator == m_services.end())
        {
            throw ItemNotFoundInRegistryException("Service by this id not found, id: " + id);
        }

        return iterator->second;
    }

private:
    std::map<Id, std::unique_ptr<Service>> m_services;
};

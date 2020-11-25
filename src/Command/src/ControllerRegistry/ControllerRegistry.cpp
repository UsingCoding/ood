#include "ControllerRegistry.hpp"
#include "Exception/ItemNotFoundInRegistryException.hpp"

void ControllerRegistry::Register(const ControllerType &id, std::unique_ptr<IController> controller)
{
    if (m_controllers.find(id) != m_controllers.end())
    {
        throw std::logic_error("Controller with the same id already registered");
    }

    m_controllers.insert(std::make_pair(id, std::move(controller)));
}

std::unique_ptr<IController> &ControllerRegistry::Get(const ControllerType &id)
{
    auto iterator = m_controllers.find(id);

    if (iterator == m_controllers.end())
    {
        throw ItemNotFoundInRegistryException("Controller by this id not found");
    }

    return iterator->second;
}

void ControllerRegistry::ForEach(std::function<void(std::pair<const ControllerType, std::unique_ptr<IController>> &)> && callback)
{
    std::for_each(m_controllers.begin(), m_controllers.end(), [&callback](std::pair<const ControllerType, std::unique_ptr<IController>> & pair){
        callback(pair);
    });
}
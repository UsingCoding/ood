#include "ControllerRegistry.hpp"
#include "Exception/ItemNotFoundInRegistryException.hpp"

void ControllerRegistry::Register(const std::string &id, std::unique_ptr<IController> commandHandler)
{
    if (m_controllers.find(id) != m_controllers.end())
    {
        throw std::logic_error("Controller with the same id already registered, id: " + id);
    }

    m_controllers.insert(std::make_pair(id, std::move(commandHandler)));
}

std::unique_ptr<IController> &ControllerRegistry::Get(const std::string &id)
{
    auto iterator = m_controllers.find(id);

    if (iterator == m_controllers.end())
    {
        throw ItemNotFoundInRegistryException("Controller by this id not found, id: " + id);
    }

    return iterator->second;
}

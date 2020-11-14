#include "ControllerRegistry.hpp"
#include "Exception/ItemNotFoundInRegistryException.hpp"

void ControllerRegistry::RegisterHandler(const std::string &id, std::unique_ptr<IController> commandHandler)
{
    if (m_handlers.find(id) != m_handlers.end())
    {
        throw std::logic_error("Controller with the same id already registered, id: " + id);
    }

    m_handlers.insert(std::make_pair(id, std::move(commandHandler)));
}

std::unique_ptr<IController> &ControllerRegistry::GetHandler(const std::string &id)
{
    auto iterator = m_handlers.find(id);

    if (iterator == m_handlers.end())
    {
        throw ItemNotFoundInRegistryException("Controller by this id not found, id: " + id);
    }

    return iterator->second;
}

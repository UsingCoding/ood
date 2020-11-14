#include "CommandHandlerRegistry.hpp"

void CommandHandlerRegistry::RegisterHandler(const std::string &id, std::unique_ptr<ICommandHandler> commandHandler)
{
    if (m_handlers.find(id) != m_handlers.end())
    {
        throw std::logic_error("Handler with the same id already registered, id: " + id);
    }

    m_handlers.insert(std::make_pair(id, std::move(commandHandler)));
}

std::unique_ptr<ICommandHandler> &CommandHandlerRegistry::GetHandler(const std::string &id)
{
    auto iterator = m_handlers.find(id);

    if (iterator == m_handlers.end())
    {
        throw std::logic_error("Handler with by this id not found, id: " + id);
    }

    return iterator->second;
}

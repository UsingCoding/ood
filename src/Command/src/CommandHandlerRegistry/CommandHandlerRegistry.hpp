#pragma once

#include "ICommandHandlerRegistry.hpp"
#include <map>

class CommandHandlerRegistry : public ICommandHandlerRegistry
{
public:
    void RegisterHandler(const std::string &id, std::unique_ptr<ICommandHandler> commandHandler) override;

    std::unique_ptr<ICommandHandler> &GetHandler(const std::string &id) override;

private:
    std::map<std::string, std::unique_ptr<ICommandHandler>> m_handlers;
};


#pragma once

#include <string>
#include <memory>
#include "../CommandHandler/ICommandHandler.hpp"

class ICommandHandlerRegistry
{
public:
    virtual void RegisterHandler(const std::string & id, std::unique_ptr<ICommandHandler> commandHandler) = 0;
    virtual std::unique_ptr<ICommandHandler> & GetHandler(const std::string & id) = 0;

    virtual ~ICommandHandlerRegistry() = default;
};

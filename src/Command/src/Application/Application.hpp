#pragma once

#include <Application/Application.hpp>
#include "../CommandHandlerRegistry/ICommandHandlerRegistry.hpp"
#include "../History/ICommandsHistory.hpp"

class Application : public Common::Application
{
public:
    Application(
        std::unique_ptr<IDocument> document,
        std::unique_ptr<ICommandHandlerRegistry> commandHandlerRegistry,
        std::unique_ptr<ICommandsHistory> commandsHistory
    )
    : m_commandHandlerRegistry(std::move(commandHandlerRegistry)),
      m_commandsHistory(std::move(commandsHistory)),
      m_document(std::move(document))
    {}

protected:
    void Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void DoRun(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::unique_ptr<IDocument> m_document;
    std::unique_ptr<ICommandHandlerRegistry> m_commandHandlerRegistry;
    std::unique_ptr<ICommandsHistory> m_commandsHistory;

    void RegisterCommandHandlers();
};


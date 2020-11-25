#pragma once

#include <Application/Application.hpp>
#include "../History/ICommandsHistory.hpp"
#include "../ControllerRegistry/IControllerRegistry.hpp"
#include "../Resource/FileResourceRepository/IFileResourceRepository.hpp"
#include "../ControllerCommandsHolder/IControllerCommandsHolder.hpp"

class Application : public Common::Application
{
public:
    Application(
        std::shared_ptr<IControllerRegistry> controllerRegistry,
        std::unique_ptr<IFileResourceRepository> & fileResourceRepository,
        std::shared_ptr<IControllerCommandsHolder> controllerCommandsHolder
    )
    : m_controllerRegistry(std::move(controllerRegistry)),
      m_fileResourceRepository(fileResourceRepository),
      m_controllerCommandsHolder(controllerCommandsHolder)
    {}

protected:
    void Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void DoRun(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::shared_ptr<IControllerRegistry> m_controllerRegistry;
    std::unique_ptr<IFileResourceRepository> & m_fileResourceRepository;
    std::shared_ptr<IControllerCommandsHolder> m_controllerCommandsHolder;

    const static std::string EXIT_COMMAND;
};


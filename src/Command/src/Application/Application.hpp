#pragma once

#include <Application/Application.hpp>
#include "../History/ICommandsHistory.hpp"
#include "../ControllerRegistry/IControllerRegistry.hpp"
#include "../Resource/FileResourceRepository/IFileResourceRepository.hpp"

class Application : public Common::Application
{
public:
    Application(
        std::unique_ptr<IControllerRegistry> controllerRegistry,
        std::unique_ptr<IFileResourceRepository> & fileResourceRepository
    )
    : m_controllerRegistry(std::move(controllerRegistry)),
      m_fileResourceRepository(fileResourceRepository)
    {}

protected:
    void Configure(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void DoRun(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::unique_ptr<IControllerRegistry> m_controllerRegistry;
    std::unique_ptr<IFileResourceRepository> & m_fileResourceRepository;

    const static std::map<std::string, ControllerType> COMMAND_CONTROLLER_MAP;
    const static std::string EXIT_COMMAND;
};


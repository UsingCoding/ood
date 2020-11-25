#pragma once

#include <Registry/IEnumerator.hpp>
#include "../IController.hpp"
#include "../ControllerType.hpp"
#include "../../ControllerCommandsHolder/IControllerCommandsHolder.hpp"
#include "../../ControllerRegistry/IControllerRegistry.hpp"
#include "../../ControllerRegistry/IControllerEnumerator.hpp"

class HelpController : public IController
{
public:
    HelpController(
        const std::shared_ptr<IControllerEnumerator> &controllerEnumerator,
        const std::shared_ptr<IControllerCommandsHolder> &controllerCommandsHolder
    )
    : m_controllerEnumerator(controllerEnumerator), m_controllerCommandsHolder(controllerCommandsHolder) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::shared_ptr<IControllerEnumerator> m_controllerEnumerator;
    std::shared_ptr<IControllerCommandsHolder> m_controllerCommandsHolder;
};


#include <iostream>
#include "HelpController.hpp"

void HelpController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{

}

void HelpController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    m_controllerEnumerator->ForEach([&](std::pair<const ControllerType, std::unique_ptr<IController>> & pair){
        *output << m_controllerCommandsHolder->GetCommandByControllerType(pair.first) << std::endl;
    });
}

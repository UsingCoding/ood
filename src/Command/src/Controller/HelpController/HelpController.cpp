#include <iostream>
#include "HelpController.hpp"

#include <Application/InputDefinition/InputDefinition.hpp>

using namespace Common::Console;

void HelpController::ConfigureInputDefinition(std::unique_ptr<IInputDefinition> &definition)
{

}

void HelpController::Handle(IInput &input, IOutput &output)
{
    std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

    m_controllerEnumerator->ForEach([&](std::pair<const ControllerType, std::unique_ptr<IController>> & pair){
        *output << m_controllerCommandsHolder->GetCommandByControllerType(pair.first) << ' ';

        pair.second->ConfigureInputDefinition(definition);

        definition->DoForEachArgument([&output](const InputArgument & argument){
            *output << '<' << argument.GetName() << '>' << ' ';
        });

        *output << std::endl;

        definition->Clear();
    });
}

#include <Application/InputDefinition/InputDefinition.hpp>
#include "Application.hpp"

using namespace Common::Console;

void Common::Application::Run(IInput &input, IOutput &output)
{
    std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

    Configure(definition);

    DoRun(input, output);
}

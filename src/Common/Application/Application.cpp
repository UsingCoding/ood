#include <Application/InputDefinition/InputDefinition.hpp>
#include <iostream>
#include "Application.hpp"

using namespace Common::Console;

void Common::Application::Run(IInput &input, IOutput &output)
{
    std::unique_ptr<IInputDefinition> definition = std::make_unique<InputDefinition>();

    definition->AddArgument(InputArgument("file_name"));

    Configure(definition);

    try
    {
        input.Bind(std::move(definition));

        input.Validate();

        DoRun(input, output);
    }
    catch (std::exception & exception)
    {
        (*output) << "Exception: " << exception.what() << std::endl;
    }
}

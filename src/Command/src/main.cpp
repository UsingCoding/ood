#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <iostream>
#include "Application/Application.hpp"
#include "CommandHandlerRegistry/CommandHandlerRegistry.hpp"
#include "History/CommandsHistory.hpp"
#include "Document/Document.hpp"

int main(int argc, char const *argv[])
{
    Common::Console::ArgvInput input(argc, argv);
    Common::Console::StreamOutput output(std::cout);

    Application application(
        std::make_unique<Document>(),
        std::make_unique<CommandHandlerRegistry>(),
        std::make_unique<CommandsHistory>()
    );

    application.Run(input, output);
}


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

    std::unique_ptr<ICommandsHistory> commandsHistory = std::make_unique<CommandsHistory>();

    Application application(
        std::make_unique<Document>(commandsHistory),
        std::make_unique<CommandHandlerRegistry>(),
        std::move(commandsHistory)
    );

    application.Run(input, output);
}


#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <iostream>
#include "Application/Application.hpp"
#include "History/CommandsHistory.hpp"
#include "Document/Document.hpp"
#include "ControllerRegistry/ControllerRegistry.hpp"
#include "Resource/FileResourceRepository/FileResourceRepository.hpp"

int main(int argc, char const *argv[])
{
    Common::Console::ArgvInput input(argc, argv);
    Common::Console::StreamOutput output(std::cout);

    std::shared_ptr<ICommandsHistory> commandsHistory = std::make_unique<CommandsHistory>();

    Application application(
        std::make_unique<Document>(commandsHistory),
        std::make_unique<ControllerRegistry>(),
        commandsHistory,
        std::make_unique<FileResourceRepository>("/home/supernotuser/dev/ood/src/Command/src/var")
    );

    application.Run(input, output);
}


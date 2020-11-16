#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <iostream>
#include "Application/Application.hpp"
#include "History/CommandsHistory.hpp"
#include "Document/Document.hpp"
#include "ControllerRegistry/ControllerRegistry.hpp"
#include "Resource/FileResourceRepository/FileResourceRepository.hpp"
#include "Document/DocumentConverter/HtmlDocumentConverter/HtmlDocumentConverter.hpp"

const static std::string REPO_PATH = "./var";

int main(int argc, char const *argv[])
{
    Common::Console::ArgvInput input(argc, argv);
    Common::Console::StreamOutput output(std::cout);

    std::shared_ptr<ICommandsHistory> commandsHistory = std::make_unique<CommandsHistory>();

    Application application(
        std::make_unique<Document>(commandsHistory, std::make_unique<HtmlDocumentConverter>()),
        std::make_unique<ControllerRegistry>(),
        commandsHistory,
        std::make_unique<FileResourceRepository>(REPO_PATH)
    );

    application.Run(input, output);
}


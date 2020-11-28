#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <iostream>
#include "Application/Application.hpp"
#include "History/CommandsHistory.hpp"
#include "Document/Document.hpp"
#include "ControllerRegistry/ControllerRegistry.hpp"
#include "Resource/FileResourceRepository/FileResourceRepository.hpp"
#include "Document/DocumentConverter/HtmlDocumentConverter/HtmlDocumentConverter.hpp"
#include "Controller/ListController/ListController.hpp"
#include "Controller/InsertParagraphController/InsertParagraphController.hpp"
#include "Controller/ReplaceTextController/ReplaceTextController.hpp"
#include "Controller/UndoController/UndoController.hpp"
#include "Controller/RedoController/RedoController.hpp"
#include "Controller/InsertImageController/InsertImageController.hpp"
#include "Controller/ResizeImageController/ResizeImageController.hpp"
#include "Controller/SaveDocumentController/SaveDocumentController.hpp"
#include "Controller/SetTitleController/SetTitleController.hpp"
#include "Controller/DeleteItemController/DeleteItemController.hpp"
#include "ControllerCommandsHolder/ControllerCommandsHolder.hpp"
#include "Controller/HelpController/HelpController.hpp"
#include "Document/AssetPathPreparer/RelativeAssetPathPreparer/RelativeAssetPathPreparer.hpp"

const static std::string REPO_PATH = "./var";

int main(int argc, char const *argv[])
{
    auto controllerRegistry = std::make_shared<ControllerRegistry>();

    std::shared_ptr<ICommandsHistory> commandsHistory = std::make_unique<CommandsHistory>();
    std::unique_ptr<IDocument> document = std::make_unique<Document>(
            commandsHistory,
            std::make_unique<HtmlDocumentConverter>(),
            std::make_unique<RelativeAssetPathPreparer>()
    );
    std::unique_ptr<IFileResourceRepository> fileResourceRepo = std::make_unique<FileResourceRepository>(REPO_PATH);
    auto controllerCommandsHolder = std::make_shared<ControllerCommandsHolder>();

    controllerRegistry->Register(ControllerType::SET_TITLE, std::make_unique<SetTitleController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::LIST, std::make_unique<ListController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::INSERT_PARAGRAPH, std::make_unique<InsertParagraphController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::REPLACE_TEXT, std::make_unique<ReplaceTextController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::UNDO, std::make_unique<UndoController>(document));
    controllerRegistry->Register(ControllerType::REDO, std::make_unique<RedoController>(document));
    controllerRegistry->Register(ControllerType::INSERT_IMAGE, std::make_unique<InsertImageController>(commandsHistory, document, fileResourceRepo));
    controllerRegistry->Register(ControllerType::RESIZE_IMAGE, std::make_unique<ResizeImageController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::SAVE_DOCUMENT, std::make_unique<SaveDocumentController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::DELETE_ITEM, std::make_unique<DeleteItemController>(commandsHistory, document));
    controllerRegistry->Register(ControllerType::HELP, std::make_unique<HelpController>(controllerRegistry, controllerCommandsHolder));

    Application application(
        controllerRegistry,
        fileResourceRepo,
        controllerCommandsHolder
    );

    Common::Console::ArgvInput input(argc, argv);
    Common::Console::StreamOutput output(std::cout);

    application.Run(input, output);
}


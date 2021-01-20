#define CATCH_CONFIG_MAIN

#include <Application/Input/ArgvInput/ArgvInput.hpp>
#include <Application/Output/StreamOutput/StreamOutput.hpp>
#include "../Catch2/catch.hpp"
#include "../src/History/CommandsHistory.hpp"
#include "CommandHistoryTests/Document/MockDocument.hpp"
#include "CommandHistoryTests/Command/MockCommand.hpp"
#include "../src/ControllerRegistry/ControllerRegistry.hpp"
#include "../src/Document/Document.hpp"
#include "DocumentTests/DocumentConverter/MockDocumentConverter.hpp"
#include "DocumentTests/AssetPathPreparer/MockAssetPathPreparer.hpp"
#include "../src/Document/DocumentConverter/HtmlDocumentConverter/HtmlDocumentConverter.hpp"
#include "../src/Resource/FileResourceRepository/IFileResourceRepository.hpp"
#include "../src/ControllerCommandsHolder/ControllerCommandsHolder.hpp"
#include "../src/Controller/SetTitleController/SetTitleController.hpp"
#include "../src/Controller/ListController/ListController.hpp"
#include "../src/Controller/InsertParagraphController/InsertParagraphController.hpp"
#include "../src/Controller/ReplaceTextController/ReplaceTextController.hpp"
#include "../src/Controller/UndoController/UndoController.hpp"
#include "../src/Controller/RedoController/RedoController.hpp"
#include "../src/Controller/InsertImageController/InsertImageController.hpp"
#include "../src/Controller/ResizeImageController/ResizeImageController.hpp"
#include "../src/Controller/SaveDocumentController/SaveDocumentController.hpp"
#include "../src/Controller/DeleteItemController/DeleteItemController.hpp"
#include "../src/Controller/HelpController/HelpController.hpp"
#include "../src/Application/Application.hpp"
#include "../src/Document/AssetPathPreparer/RelativeAssetPathPreparer/RelativeAssetPathPreparer.hpp"
#include "ApplicationTests/FileResourceRepository/MockFileResourceRepository.hpp"

SCENARIO("Using command history to undo commands and redo commands")
{
    GIVEN("CommandsHistory and mock document, and mock command with call stack vector passed to constructor")
    {
        CommandsHistory commandsHistory;

        CommandHistoryTests::MockDocument document;

        std::vector<std::string> callStack;
        std::vector<std::string> disposeStack;

        auto firstCommand = std::make_unique<CommandHistoryTests::MockCommand>("first", callStack, disposeStack);
        auto secondCommand = std::make_unique<CommandHistoryTests::MockCommand>("second", callStack, disposeStack);
        auto thirdCommand = std::make_unique<CommandHistoryTests::MockCommand>("third", callStack, disposeStack);

        WHEN("We send command to history we immediately execute her")
        {
            commandsHistory.AddAndExecuteCommand(std::move(firstCommand), document);

            THEN("Command call stack will have size == 1 and first element equal to first command id, dispose stack is empty")
            {
                REQUIRE(callStack.size() == 1);
                REQUIRE(callStack.at(0) == "first");

                REQUIRE(disposeStack.size() == 0);
            }

            AND_WHEN("We add second command")
            {
                commandsHistory.AddAndExecuteCommand(std::move(secondCommand), document);

                THEN("Command call stack will have size == 2 and first element equal to first command id, second element equal to second command id, dispose stack is empty")
                {
                    REQUIRE(callStack.size() == 2);

                    REQUIRE(callStack.at(0) == "first");
                    REQUIRE(callStack.at(1) == "second");

                    REQUIRE(disposeStack.size() == 0);
                }

                AND_WHEN("We undo command")
                {
                    REQUIRE_NOTHROW(commandsHistory.Undo(document));

                    THEN("Call stack size will be equal to 1 and first element will be with id of first command and dispose stack steel empty")
                    {
                        REQUIRE(callStack.size() == 1);
                        REQUIRE(callStack.at(0) == "first");

                        REQUIRE(disposeStack.size() == 0);
                    }

                    AND_WHEN("We redo command")
                    {
                        REQUIRE_NOTHROW(commandsHistory.Redo(document));

                        THEN("At second element in callStack will be a id of second command")
                        {
                            REQUIRE(callStack.size() == 2);
                            REQUIRE(callStack.at(1) == "second");
                        }

                        AND_WHEN("We undo command again and insert third command")
                        {
                            REQUIRE_NOTHROW(commandsHistory.Undo(document));
                            REQUIRE_NOTHROW(commandsHistory.AddAndExecuteCommand(std::move(thirdCommand), document));

                            THEN("Call stack size will be 2, at second argument there will be id of third command. Id of second command will be added to dispose stack")
                            {
                                REQUIRE(callStack.size() == 2);
                                REQUIRE(callStack.at(0) == "first");
                                REQUIRE(callStack.at(1) == "third");

                                REQUIRE(disposeStack.size() == 0);
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Testing document")
{
    GIVEN("A document")
    {
        Document document(
            std::make_unique<CommandsHistory>(),
            std::make_unique<DocumentTests::MockDocumentConverter>(),
            std::make_unique<DocumentTests::MockAssetPathPreparer>()
        );

        WHEN("We add new image")
        {
            auto path = "/path/to/image.png";
            REQUIRE_NOTHROW(document.InsertImage(path, 100, 100, std::nullopt));

            THEN("We got elements count == 1, at first place will be image with path we set")
            {
                REQUIRE(document.GetItemsCount() == 1);
                REQUIRE_NOTHROW(document.GetItem(0));

                auto item = document.GetItem(0);

                REQUIRE(item.GetImage() != nullptr);
                REQUIRE(item.GetParagraph() == nullptr);

                REQUIRE(item.GetImage()->GetPath() == path);
            }
            
            WHEN("We insert paragraph at end")
            {
                auto text = "New message for text";
                REQUIRE_NOTHROW(document.InsertParagraph(text, std::nullopt));
                
                THEN("We got elements count == 2, at second element will be paragraph with text we set")
                {
                    REQUIRE(document.GetItemsCount() == 2);
                    REQUIRE_NOTHROW(document.GetItem(1));

                    auto item = document.GetItem(1);

                    REQUIRE(item.GetParagraph() != nullptr);
                    REQUIRE(item.GetImage() == nullptr);

                    REQUIRE(item.GetParagraph()->GetText() == text);
                }

                AND_WHEN("We insert new paragraph at first position")
                {
                    auto newText = "New message for new text";
                    REQUIRE_NOTHROW(document.InsertParagraph(newText, 1));

                    THEN("We got at first position out new paragraph and at second position previous added paragraph")
                    {
                        REQUIRE(document.GetItemsCount() == 3);
                        REQUIRE_NOTHROW(document.GetItem(1));
                        REQUIRE_NOTHROW(document.GetItem(2));

                        auto newParagraph = document.GetItem(1);
                        auto previousParagraph = document.GetItem(2);

                        REQUIRE(newParagraph.GetParagraph() != nullptr);
                        REQUIRE(newParagraph.GetImage() == nullptr);

                        REQUIRE(newParagraph.GetParagraph()->GetText() == newText);

                        REQUIRE(previousParagraph.GetParagraph() != nullptr);
                        REQUIRE(previousParagraph.GetImage() == nullptr);

                        REQUIRE(previousParagraph.GetParagraph()->GetText() == text);
                    }

                    AND_WHEN("We deleting item at first position")
                    {
                        REQUIRE_NOTHROW(document.DeleteItem(1));

                        THEN("At first position will be first added paragraph and at zero image")
                        {
                            REQUIRE(document.GetItemsCount() == 2);
                            REQUIRE_NOTHROW(document.GetItem(0));

                            auto image = document.GetItem(0);

                            REQUIRE(image.GetImage() != nullptr);
                            REQUIRE(image.GetParagraph() == nullptr);

                            REQUIRE(image.GetImage()->GetPath() == path);

                            REQUIRE_NOTHROW(document.GetItem(1));

                            auto paragraph = document.GetItem(1);

                            REQUIRE(paragraph.GetParagraph() != nullptr);
                            REQUIRE(paragraph.GetImage() == nullptr);

                            REQUIRE(paragraph.GetParagraph()->GetText() == text);
                        }
                    }
                }
            }
        }

        WHEN("We set new title")
        {
            REQUIRE(document.GetTitle() == "");

            auto title = "Html is programming language";
            REQUIRE_NOTHROW(document.SetTitle(title));

            THEN("We can receive new title")
            {
                REQUIRE(document.GetTitle() == title);
            }
        }


    }
}

SCENARIO("Using application to create a simple document")
{
    GIVEN("Application")
    {
        auto controllerRegistry = std::make_shared<ControllerRegistry>();

        std::shared_ptr<ICommandsHistory> commandsHistory = std::make_unique<CommandsHistory>();
        std::unique_ptr<IDocument> document = std::make_unique<Document>(
                commandsHistory,
                std::make_unique<HtmlDocumentConverter>(),
                std::make_unique<RelativeAssetPathPreparer>()
        );
        std::unique_ptr<IFileResourceRepository> fileResourceRepo = std::make_unique<ApplicationTests::MockFileResourceRepository>();
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

        std::stringstream istream;
        std::stringstream ostream;

        auto inputArgs = std::make_unique<std::vector<std::string>>();

        inputArgs->push_back("main");

        Common::Console::ArgvInput input(std::move(inputArgs), istream);
        Common::Console::StreamOutput output(ostream);

        WHEN("We set new title")
        {
            std::string title = "new title";
            REQUIRE_NOTHROW(istream << "SetTitle " << title << "\n");

            WHEN("We run command to insert paragraph")
            {
                std::string paragraphText = "Useful text";
                REQUIRE_NOTHROW(istream << "InsertParagraph end " << paragraphText << "\n");

                AND_WHEN("We call List to show all elements ant title and exit to stop application")
                {
                    REQUIRE_NOTHROW(istream << "List\n");
                    REQUIRE_NOTHROW(istream << "Exit\n");

                    THEN("We Run application")
                    {
                        REQUIRE_NOTHROW(application.Run(input, output));

                        AND_THEN("We go two message about that commands executed successfully and list of elements")
                        {
                            std::string outputString;

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Run");

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Command executed successfully");

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Command executed successfully");

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Title: " + title);

                            getline(ostream, outputString);
                            REQUIRE(outputString == "0. Paragraph: " + paragraphText);

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Command executed successfully");

                            getline(ostream, outputString);
                            REQUIRE(outputString == "Exit");
                        }
                    }
                }
            }
        }

        WHEN("We passing unknown command")
        {
            istream.clear();
            ostream.clear();

            REQUIRE_NOTHROW(istream << "InsertQuarter\n");
            REQUIRE_NOTHROW(istream << "Exit\n");

            THEN("We got got message about it")
            {
                REQUIRE_NOTHROW(application.Run(input, output));

                std::string outputString;

                getline(ostream, outputString);
                REQUIRE(outputString == "Run");

                getline(ostream, outputString);
                REQUIRE(outputString == "Unknown command");

                getline(ostream, outputString);
                REQUIRE(outputString == "Exit");
            }
        }

        WHEN("We pass no arguments")
        {
            istream.clear();
            ostream.clear();

            REQUIRE_NOTHROW(istream << "\n");
            REQUIRE_NOTHROW(istream << "Exit\n");

            THEN("We got got message about it")
            {
                REQUIRE_NOTHROW(application.Run(input, output));

                std::string outputString;

                getline(ostream, outputString);
                REQUIRE(outputString == "Run");

                getline(ostream, outputString);
                REQUIRE(outputString == "You must provide more than zero arguments");

                getline(ostream, outputString);
                REQUIRE(outputString == "Exit");
            }
        }

        WHEN("We pass one command and second command with incorrect arguments")
        {
            istream.clear();
            ostream.clear();

            std::string text = "Incredible text";
            REQUIRE_NOTHROW(istream << "InsertParagraph end " << text << " \n");
            REQUIRE_NOTHROW(istream << "InsertParagraph text " << text << " \n");
            REQUIRE_NOTHROW(istream << "List\n");
            REQUIRE_NOTHROW(istream << "Exit\n");

            THEN("We got messages that first command successfully executed and second has incorrect arguments passed")
            {
                REQUIRE_NOTHROW(application.Run(input, output));

                std::string outputString;

                getline(ostream, outputString);
                REQUIRE(outputString == "Run");

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Invalid argument provided for position");

                getline(ostream, outputString);
                getline(ostream, outputString);
                REQUIRE(outputString == "0. Paragraph: " + text);

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Exit");
            }
        }

        WHEN("Inserting a image in document")
        {
            istream.clear();
            ostream.clear();

            std::string path = "/path/to/image.png";
            std::string sizes = "100 100";
            REQUIRE_NOTHROW(istream << "InsertImage end " << sizes << " " << path << " \n");
            REQUIRE_NOTHROW(istream << "List\n");
            REQUIRE_NOTHROW(istream << "Exit\n");

            THEN("We got message that command executed and image added")
            {
                REQUIRE_NOTHROW(application.Run(input, output));

                std::string outputString;

                getline(ostream, outputString);
                REQUIRE(outputString == "Run");

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Title: ");

                getline(ostream, outputString);
                REQUIRE(outputString == "0. Image: " + sizes + " " + "\"" + path + "\"");

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");
            }
        }

        WHEN("We deleting already added element")
        {
            istream.clear();
            ostream.clear();

            std::string text = "Incredible text";
            REQUIRE_NOTHROW(istream << "InsertParagraph end " << text << " \n");
            REQUIRE_NOTHROW(istream << "List\n");
            REQUIRE_NOTHROW(istream << "DeleteItem 1\n");
            REQUIRE_NOTHROW(istream << "DeleteItem 0\n");
            REQUIRE_NOTHROW(istream << "List\n");
            REQUIRE_NOTHROW(istream << "Exit\n");

            THEN("We got messages that deleting on unknown position and the second one is we successfully delete item")
            {
                REQUIRE_NOTHROW(application.Run(input, output));

                std::string outputString;

                getline(ostream, outputString);
                REQUIRE(outputString == "Run");

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Title: ");

                getline(ostream, outputString);
                REQUIRE(outputString == "0. Paragraph: " + text);

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Requested item by index more than count of items");

                getline(ostream, outputString);
                REQUIRE(outputString == "Command executed successfully");

                getline(ostream, outputString);
                REQUIRE(outputString == "Title: ");
            }
        }
    }
}

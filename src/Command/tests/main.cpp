#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../src/History/CommandsHistory.hpp"
#include "CommandHistoryTests/Document/MockDocument.hpp"
#include "CommandHistoryTests/Command/MockCommand.hpp"
#include "../src/ControllerRegistry/ControllerRegistry.hpp"
#include "ControllerRegistryTests/Controller/MockController.hpp"
#include "../src/Document/Document.hpp"
#include "DocumentTests/DocumentConverter/MockDocumentConverter.hpp"
#include "DocumentTests/AssetPathPreparer/MockAssetPathPreparer.hpp"

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

                                REQUIRE(disposeStack.size() == 1);
                                REQUIRE(disposeStack.at(0) == "second");
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

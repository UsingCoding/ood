#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "../src/History/CommandsHistory.hpp"
#include "CommandHistoryTests/Document/MockDocument.hpp"
#include "CommandHistoryTests/Command/MockCommand.hpp"

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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"

#include "Observerable/MockObservable.hpp"
#include "Observer/MockObserver.hpp"

SCENARIO("Checking priority of observers")
{
    GIVEN("Mock observable and observers and callStack to keep state")
    {
        MockObservable mockObservable;

        std::shared_ptr<std::stack<std::string>> callStack = std::make_shared<std::stack<std::string>>();

        MockObserver mockObserver1("First", callStack);
        MockObserver mockObserver2("Second", callStack);

        AND_GIVEN("Observers subscribed to observable to call in priority that declared by their names and finalCallStack")
        {
            mockObservable.RegisterObserver(2, mockObserver1);
            mockObservable.RegisterObserver(1, mockObserver2);

            std::shared_ptr<std::stack<std::string>> finalCallStack = std::make_shared<std::stack<std::string>>();

            finalCallStack->push("First");
            finalCallStack->push("Second");

            WHEN("We notify observers")
            {
                mockObservable.NotifyObservers();

                THEN("Observers filled callStack and he must be equal to finalCallStack")
                {
                    REQUIRE(*(callStack) == *(finalCallStack));
                }
            }
        }

        AND_GIVEN("Observers subscribed in reverse order to observable to call in priority that declared by their names and finalCallStack")
        {
            mockObservable.RegisterObserver(1, mockObserver1);
            mockObservable.RegisterObserver(2, mockObserver2);

            std::shared_ptr<std::stack<std::string>> finalCallStack = std::make_shared<std::stack<std::string>>();

            finalCallStack->push("First");
            finalCallStack->push("Second");

            WHEN("We notify observers")
            {
                mockObservable.NotifyObservers();

                THEN("Observers filled callStack and he must be not equal to finalCallStack")
                {
                    REQUIRE(*(callStack) != *(finalCallStack));
                }
            }
        }
    }
}

SCENARIO("Observers subscribed in one priority")
{
    GIVEN("Mock observable and observers and callStack to keep state")
    {
        MockObservable mockObservable;

        std::shared_ptr<std::stack<std::string>> callStack = std::make_shared<std::stack<std::string>>();

        MockObserver mockObserver1("First", callStack);
        MockObserver mockObserver2("Second", callStack);
        MockObserver mockObserver3("Third", callStack);

        AND_GIVEN("Observers subscribed to observable in same priority and third observer in higher priority")
        {
            mockObservable.RegisterObserver(1, mockObserver1);
            mockObservable.RegisterObserver(1, mockObserver2);
            mockObservable.RegisterObserver(2, mockObserver3);

            std::shared_ptr<std::stack<std::string>> finalCallStack = std::make_shared<std::stack<std::string>>();

            finalCallStack->push("Third");
            finalCallStack->push("Second");
            finalCallStack->push("First");

            WHEN("We notify observers")
            {
                mockObservable.NotifyObservers();

                THEN("Observers filled callStack and he must be not equal to finalCallStack and observers with same priority called sequently")
                {
                    REQUIRE(*(callStack) == *(finalCallStack));
                }
            }
        }
    }
}
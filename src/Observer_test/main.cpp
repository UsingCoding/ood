#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "PriorityTest/Observable/MockObservable.hpp"
#include "PriorityTest/Observer/MockObserver.hpp"
#include "../Observer/WeatherData/WeatherData.hpp"
#include "FewObservableTest/Observer/MockObserver.hpp"

SCENARIO("Checking priority of observers")
{
    GIVEN("Mock observable and observers and callStack to keep state")
    {
        PriorityTest::MockObservable mockObservable;

        std::shared_ptr<std::stack<std::string>> callStack = std::make_shared<std::stack<std::string>>();

        std::string first = "First";
        std::string second = "Second";

        PriorityTest::MockObserver mockObserver1(std::move(first), callStack);
        PriorityTest::MockObserver mockObserver2(std::move(second), callStack);

        AND_GIVEN("Observers subscribed to observable to call in priority that declared by their names and finalCallStack")
        {
            mockObservable.RegisterObserver(2, mockObserver1);
            mockObservable.RegisterObserver(1, mockObserver2);

            std::shared_ptr<std::stack<std::string>> finalCallStack = std::make_shared<std::stack<std::string>>();

            finalCallStack->push(std::move(first));
            finalCallStack->push(std::move(second));

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
        PriorityTest::MockObservable mockObservable;

        std::shared_ptr<std::stack<std::string>> callStack = std::make_shared<std::stack<std::string>>();

        std::string first = "First";
        std::string second = "Second";
        std::string third = "Third";

        PriorityTest::MockObserver mockObserver1(std::move(first), callStack);
        PriorityTest::MockObserver mockObserver2(std::move(second), callStack);
        PriorityTest::MockObserver mockObserver3(std::move(third), callStack);

        AND_GIVEN("Observers subscribed to observable in same priority and third observer in higher priority")
        {
            mockObservable.RegisterObserver(1, mockObserver1);
            mockObservable.RegisterObserver(1, mockObserver2);
            mockObservable.RegisterObserver(2, mockObserver3);

            std::shared_ptr<std::stack<std::string>> finalCallStack = std::make_shared<std::stack<std::string>>();

            finalCallStack->push(std::move(third));
            finalCallStack->push(std::move(second));
            finalCallStack->push(std::move(first));

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

SCENARIO("Getting know about from what station message received")
{
    GIVEN("Two weather stations, Inner and Outer")
    {
        WeatherData weatherDataIn(WeatherDataSource::IN);
        WeatherData weatherDataOut(WeatherDataSource::OUT);

        AND_GIVEN("Mock observer subscribed to weather stations")
        {
            FewObservableTest::MockObserver observer;

            weatherDataIn.RegisterObserver(0, observer);
            weatherDataOut.RegisterObserver(0, observer);

            WHEN("Inner weather station start event")
            {
                weatherDataIn.SetMeasurements(30, 2, 4);

                THEN("In observer saved from what station received message and it equals to inner station")
                {
                    REQUIRE(observer.GetSource() == WeatherDataSource::IN);
                }
            }

            WHEN("Outer weather station start event")
            {
                weatherDataOut.SetMeasurements(30, 2, 4);

                THEN("In observer saved from what station received message and it equals to inner station")
                {
                    REQUIRE(observer.GetSource() == WeatherDataSource::OUT);
                }
            }
        }
    }
}
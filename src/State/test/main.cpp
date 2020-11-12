#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "MockGumBallMachine/MockGumBallMachine.hpp"
#include "../src/GumBallMachineWithState/GumBallMachine/GumBallMachineWithStaticState/GumBallMachineWithStaticState.hpp"
#include "StreamBufferOverrider/StreamBufferOverrider.hpp"
#include "../src/NaiveGumBallMachine/GumBallMachine.hpp"

typedef State::MockGumBallMachine::MOCK_STATE GumBallMachineState;

SCENARIO("We can`t receive balls if there out")
{
    GIVEN("Mock gumball machine with 0 balls")
    {
        State::MockGumBallMachine machine(0);

        WHEN("In begin we have state sold out")
        {
            REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);

            AND_WHEN("We insert a quarter (call insert quarter in current state)")
            {
                machine.GetState()->InsertQuarter();

                THEN("We did`nt change the state")
                {
                    REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);
                }
            }

            AND_WHEN("We turn crank")
            {
                THEN("State did`nt changed")
                {
                    REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);

                    AND_WHEN("After dispense state changed to Sold out")
                    {
                        machine.GetState()->Dispense();

                        REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);
                    }
                }
            }
        }
    }
}

SCENARIO("Buying ball from gumball machine")
{
    GIVEN("Gumball machine")
    {
        GumBallWithState::GumBallMachineWithStaticState machine(2);

        std::stringstream buffer;

        StreamBufferOverrider streamBufferOverrider(std::cout, buffer);

        WHEN("We insert a quarter")
        {
            machine.InsertQuarter();

            THEN("We got message that we insert a quarter")
            {
                std::string message;
                getline(buffer, message);
                REQUIRE(message == "You inserted a quarter");
            }

            AND_WHEN("We we insert another quarter")
            {
                machine.InsertQuarter();

                THEN("We got message about that")
                {
                    std::string message;
                    getline(buffer, message);
                    REQUIRE(message == "You inserted a quarter");

                    AND_WHEN("We turn crank")
                    {
                        machine.TurnCrank();

                        THEN("We got message that we turned and than gumball rolling out")
                        {
                            getline(buffer, message);
                            REQUIRE(message == "You turned...");

                            getline(buffer, message);
                            REQUIRE(message == "A gumball comes rolling out the slot...");

                            AND_WHEN("We turn crank again")
                            {
                                machine.TurnCrank();

                                THEN("We got message that we turned and than gumball rolling out and message that out of gumballs")
                                {
                                    getline(buffer, message);
                                    REQUIRE(message == "You turned...");

                                    getline(buffer, message);
                                    REQUIRE(message == "A gumball comes rolling out the slot...");

                                    getline(buffer, message);
                                    REQUIRE(message == "Oops, out of gumballs");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Insert coins and buying in naive machine realization ")
{
    GIVEN("Naive machine realization")
    {
        Naive::GumBallMachine machine(5);

        std::stringstream buffer;

        StreamBufferOverrider streamBufferOverrider(std::cout, buffer);

        WHEN("We inject quarter twice")
        {
            machine.InsertQuarter();
            machine.InsertQuarter();

            THEN("We got message about it")
            {
                std::string message;

                getline(buffer, message);
                REQUIRE(message == "You inserted a quarter");

                getline(buffer, message);
                REQUIRE(message == "You inserted a quarter");

                AND_WHEN("We eject quarter")
                {
                    machine.EjectQuarter();

                    THEN("We got message that coins is ejected and number of coins")
                    {
                        getline(buffer, message);
                        REQUIRE(message == "Quarter(s) returned: 2");
                    }
                }
            }
        }
    }

    GIVEN("Naive machine realization with 2 gumballs")
    {
        Naive::GumBallMachine machine(2);

        std::stringstream buffer;

        StreamBufferOverrider streamBufferOverrider(std::cout, buffer);

        WHEN("We inject quarter twice")
        {
            machine.InsertQuarter();
            machine.InsertQuarter();

            AND_WHEN("We turn crank")
            {
                machine.TurnCrank();

                THEN("We got message about it")
                {
                    std::string message;

                    getline(buffer, message);
                    REQUIRE(message == "You inserted a quarter");

                    getline(buffer, message);
                    REQUIRE(message == "You inserted a quarter");

                    getline(buffer, message);
                    REQUIRE(message == "You turned...");

                    getline(buffer, message);
                    REQUIRE(message == "A gumball comes rolling out the slot");

                    AND_WHEN("We eject coin")
                    {
                        machine.EjectQuarter();

                        THEN("We got message that ejected one coin")
                        {
                            getline(buffer, message);
                            REQUIRE(message == "Quarter(s) returned: 1");

                            AND_WHEN("We insert quarter")
                            {
                                machine.InsertQuarter();

                                AND_WHEN("We turn crank")
                                {
                                    machine.TurnCrank();

                                    THEN("We got message that ball is rolling is balls is out")
                                    {
                                        getline(buffer, message);
                                        REQUIRE(message == "You inserted a quarter");

                                        getline(buffer, message);
                                        REQUIRE(message == "You turned...");

                                        getline(buffer, message);
                                        REQUIRE(message == "A gumball comes rolling out the slot");

                                        getline(buffer, message);
                                        REQUIRE(message == "Oops, out of gumballs");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Trying to buy without money and eject quarter")
{
    GIVEN("Mock gumball machine")
    {
        State::MockGumBallMachine machine(5);

        WHEN("We turn crank without insert quarter step")
        {
            machine.GetState()->TurnCrank();

            THEN("We did`nt change state")
            {
                REQUIRE(machine.GetMockState() == GumBallMachineState::NO_QUARTER);
            }
        }

        WHEN("We eject quarter without insert quarter step")
        {
            machine.GetState()->EjectQuarter();

            THEN("We did`nt change state")
            {
                REQUIRE(machine.GetMockState() == GumBallMachineState::NO_QUARTER);
            }
        }
    }
}

SCENARIO("Receiving a ball if gumball machine has balls")
{
    GIVEN("Mock gumball with few balls")
    {
        State::MockGumBallMachine machine(2);

        WHEN("We insert a quarter")
        {
            machine.GetState()->InsertQuarter();

            THEN("Now state is Has Quarter")
            {
                REQUIRE(machine.GetMockState() == GumBallMachineState::HAS_QUARTER);
            }

            AND_WHEN("We turn crank")
            {
                machine.GetState()->TurnCrank();

                THEN("We have state sold")
                {
                    REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD);
                }

                AND_WHEN("We dispense ball")
                {
                    machine.GetState()->Dispense();

                    THEN("We have state No quarter state")
                    {
                        REQUIRE(machine.GetMockState() == GumBallMachineState::NO_QUARTER);
                    }

                    AND_WHEN("We again insert a quarter, turn crank")
                    {
                        machine.GetState()->InsertQuarter();
                        machine.GetState()->TurnCrank();

                        THEN("We Got state sold")
                        {
                            REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD);
                        }

                        AND_WHEN("We dispense ball")
                        {
                            machine.GetState()->Dispense();

                            THEN("We got state sold out")
                            {
                                REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Insert several coins to machine")
{
    GIVEN("Mock gumball machine with 1 ball")
    {
        State::MockGumBallMachine machine(3);

        WHEN("We twice insert quarter")
        {
            machine.GetState()->InsertQuarter();
            machine.GetState()->InsertQuarter();
            machine.GetState()->InsertQuarter();
            machine.GetState()->InsertQuarter();

            THEN("Coins in machine is 4")
            {
                REQUIRE(machine.GetCoinsCount() == 4);

                AND_THEN("Machine state is has quarter")
                {
                    REQUIRE(machine.GetMockState() == GumBallMachineState::HAS_QUARTER);
                }
            }

            AND_WHEN("We turn crank")
            {
                machine.GetState()->TurnCrank();

                AND_WHEN("We dispense")
                {
                    machine.GetState()->Dispense();

                    THEN("We have state sold out cause coins was more than balls")
                    {
                        REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);
                    }
                }
            }
        }

        WHEN("We insert 2 quarter")
        {
            machine.GetState()->InsertQuarter();
            machine.GetState()->InsertQuarter();

            AND_WHEN("We turn crank")
            {
                machine.GetState()->TurnCrank();

                AND_WHEN("We dispense")
                {
                    machine.GetState()->Dispense();

                    THEN("We have state has quarter, cause we have 1 quarter in machine")
                    {
                        REQUIRE(machine.GetMockState() == GumBallMachineState::HAS_QUARTER);
                    }

                    AND_WHEN("We turn crank and dispense again")
                    {
                        machine.GetState()->TurnCrank();
                        machine.GetState()->Dispense();

                        THEN("We have state sold out")
                        {
                            REQUIRE(machine.GetMockState() == GumBallMachineState::SOLD_OUT);
                        }
                    }
                }
            }
        }
    }
}
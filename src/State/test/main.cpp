#define CATCH_CONFIG_MAIN
#include "../Catch2/catch.hpp"
#include "MockGumBallMachine/MockGumBallMachine.hpp"

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
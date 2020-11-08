#include <iostream>
#include "GumBallMachineWithState/GumBallMachine/GumBallMachine.hpp"
#include "NaiveGumBallMachine/GumBallMachine.hpp"
#include "GumBallMachineWithDynamicallyCreatedState/GumBallMachine/GumBallMachine.hpp"

using namespace std;

template <typename GumballMachineType>
void TestGumballMachine(GumballMachineType & m)
{
    cout << m.ToString() << endl;

    m.InsertQuarter();
    m.TurnCrank();

    cout << m.ToString() << endl;

    m.InsertQuarter();
    m.EjectQuarter();
    m.TurnCrank();

    cout << m.ToString() << endl;

    m.InsertQuarter();
    m.TurnCrank();
    m.InsertQuarter();
    m.TurnCrank();
    m.EjectQuarter();

    cout << m.ToString() << endl;

    m.InsertQuarter();
    m.InsertQuarter();
    m.TurnCrank();
    m.InsertQuarter();
    m.TurnCrank();
    m.InsertQuarter();
    m.TurnCrank();

    cout << m.ToString() << endl;
}

void TestNaiveGumballMachine()
{
    Naive::GumBallMachine m(5);
    TestGumballMachine(m);
}


void TestGumballMachineWithState()
{
    GumBallWithState::GumBallMachine m(5);
    TestGumballMachine(m);
}

void TestGumballMachineWithDynamicState()
{
    GumBallWithDynamicState::GumBallMachine m(5);
    TestGumballMachine(m);
}

int main()
{
    TestNaiveGumballMachine();

    cout << "\n-----------------\n";
    TestGumballMachineWithState();

    cout << "\n-----------------\n";
    TestGumballMachineWithDynamicState();

    return 0;
}
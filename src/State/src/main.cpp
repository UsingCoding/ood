#include <iostream>
#include "GumBallMachineWithState/GumBallMachine/GumBallMachine.hpp"

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

//void TestNaiveGumballMachine()
//{
//    naive::CGumballMachine m(5);
//    TestGumballMachine(m);
//}


void TestGumballMachineWithState()
{
    GumBallWithState::GumBallMachine m(5);
    TestGumballMachine(m);
}

//void TestGumballMachineWithDynamicState()
//{
//    with_dynamic_state::CGumballMachine m(5);
//    TestGumballMachine(m);
//}

int main()
{
//    TestNaiveGumballMachine();

    cout << "\n-----------------\n";
    TestGumballMachineWithState();

    cout << "\n-----------------\n";
//    TestGumballMachineWithDynamicState();

    return 0;
}
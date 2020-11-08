#pragma once

#include <iostream>
#include <Strings.hpp>

class GumBallMachine
{
public:
    enum class State
    {
        SoldOut,		// Жвачка закончилась
        NoQuarter,		// Нет монетки
        HasQuarter,		// Есть монетка
        Sold,			// Монетка выдана
    };

    GumBallMachine(unsigned count)
            : m_count(count)
            , m_state(count > 0 ? State::NoQuarter : State::SoldOut)
    {
    }

    void InsertQuarter()
    {
        switch (m_state)
        {
            case State::SoldOut:
                std::cout << "You can't insert a quarter, the machine is sold out\n";
                break;
            case State::NoQuarter:
                std::cout << "You inserted a quarter\n";
                m_state = State::HasQuarter;
                break;
            case State::HasQuarter:
                std::cout << "You can't insert another quarter\n";
                break;
            case State::Sold:
                std::cout << "Please wait, we're already giving you a gumball\n";
                break;
        }
    }

    void EjectQuarter()
    {
        using namespace std;
        switch (m_state)
        {
            case State::HasQuarter:
                cout << "Quarter returned\n";
                m_state = State::NoQuarter;
                break;
            case State::NoQuarter:
                cout << "You haven't inserted a quarter\n";
                break;
            case State::Sold:
                cout << "Sorry you already turned the crank\n";
                break;
            case State::SoldOut:
                cout << "You can't eject, you haven't inserted a quarter yet\n";
                break;
        }
    }

    void TurnCrank()
    {
        using namespace std;
        switch (m_state)
        {
            case State::SoldOut:
                cout << "You turned but there's no gumballs\n";
                break;
            case State::NoQuarter:
                cout << "You turned but there's no quarter\n";
                break;
            case State::HasQuarter:
                cout << "You turned...\n";
                m_state = State::Sold;
                Dispense();
                break;
            case State::Sold:
                cout << "Turning twice doesn't get you another gumball\n";
                break;
        }
    }

    void Refill(unsigned numBalls)
    {
        m_count = numBalls;
        m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
    }

    std::string ToString()const
    {
        std::string state =
                (m_state == State::SoldOut)    ? "sold out" :
                (m_state == State::NoQuarter)  ? "waiting for quarter" :
                (m_state == State::HasQuarter) ? "waiting for turn of crank"
                                               : "delivering a gumball";

        return Strings::Concatenator() <<
        "Mighty Gumball, Inc.\n" <<
        "C++-enabled Standing Gumball Model #2016\n" <<
        "Inventory: " << m_count << " gumball" << (m_count != 1 ? "s" : "") << '\n' <<
        "Machine is " << state;
    }

private:
    void Dispense()
    {
        using namespace std;
        switch (m_state)
        {
            case State::Sold:
                cout << "A gumball comes rolling out the slot\n";
                --m_count;
                if (m_count == 0)
                {
                    cout << "Oops, out of gumballs\n";
                    m_state = State::SoldOut;
                }
                else
                {
                    m_state = State::NoQuarter;
                }
                break;
            case State::NoQuarter:
                cout << "You need to pay first\n";
                break;
            case State::SoldOut:
            case State::HasQuarter:
                cout << "No gumball dispensed\n";
                break;
        }
    }

    unsigned m_count;
    State m_state = State::SoldOut;
};

/*
    ==================================================
    Flights Management
    ==================================================
    Name   : Nozhin Azarpanah
    Date   : February 17, 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

#include "Flight.h"

using namespace std;

namespace sdds 
{
    void Flight::emptyPlane()
    {
        m_passengers = 0;
        m_fuel = 0.00;
    }

    Flight::Flight() 
    {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title) 
    {
        emptyPlane();

        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 && fuel <= FuelTankCapacity)
        {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const 
    {
        if (*this) 
        {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) 
        {
            cout << " Flight  |  Empty Plane    ";
        }
        else 
        {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const
    {
        int needed = m_passengers * 600;

        if (m_passengers > 0 && m_fuel >= needed) 
        {
            return true;
        }
        return false;
    }

    Flight::operator int() const 
    {
        return m_passengers;
    }

    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator const char* () const
    {
        return m_title;
    }

    bool Flight::operator ~() const 
    {
        if (m_passengers == 0) 
        {
            return true;
        }
        return false;
    }

    Flight& Flight::operator=(Flight& flight)
    {
        m_passengers = flight.m_passengers;
        m_fuel = flight.m_fuel;
        strcpy(m_title, flight.m_title);
        flight.emptyPlane();
        return *this;
    }

    Flight& Flight::operator=(const int numOfPassengers)
    {
        if (numOfPassengers > 0 && numOfPassengers <= Boen747Capacity)
        {
            m_passengers = numOfPassengers;
            strcpy(m_title, "EmptyPlane");
        }

        return *this;
    }

    Flight& Flight::operator=(const double fuel) 
    {
        if (fuel > 0 && fuel < FuelTankCapacity)
        {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(double value)
    {
        if (value > 0 && m_fuel < FuelTankCapacity && m_fuel + value <= FuelTankCapacity)
        {
            m_fuel += value;
        }
        else if (m_fuel + value > FuelTankCapacity) 
        {
            m_fuel = FuelTankCapacity;
        }
        return *this;
    }

    Flight& Flight::operator+=(int value) 
    {
        if (value > 0 && m_passengers < Boen747Capacity && value + m_passengers <= Boen747Capacity)
        {
            m_passengers += value;
        }
        else if (value + m_passengers > Boen747Capacity) 
        {
            m_passengers = Boen747Capacity;
        }
        return *this;
    }

    Flight& Flight::operator-=(double value) 
    {
        if (value > 0 && m_fuel != 0 && m_fuel - value >= 0) 
        {
            m_fuel -= value;
        }
        else if (m_fuel - value < 0)
        {
            m_fuel = 0;
        }
        return *this;
    }

    Flight& Flight::operator-=(int value) 
    {
        if (value > 0 && m_passengers != 0 && m_passengers - value >= 0)
        {
            m_passengers -= value;
        }
        else if (m_passengers - value < 0) 
        {
            m_passengers = 0;
        }
        return *this;
    }

    int operator+(const Flight& flight1, const Flight& flight2) 
    {
        int sum = 0;

        if (flight1.getFlightPassengers() <= 0 || flight1.getFlightFuel() <= 0.00 || flight1.getFlightPassengers() > Boen747Capacity || flight1.getFlightFuel() > FuelTankCapacity)
        {
            if (flight2.getFlightPassengers() <= 0 || flight2.getFlightFuel() <= 0.00 || flight2.getFlightPassengers() > Boen747Capacity || flight2.getFlightFuel() > FuelTankCapacity)
            {
                sum = 0;
            }
        }
        else 
        {
            sum = flight1.getFlightPassengers() + flight2.getFlightPassengers();
        }
        return sum;
    }

    int operator+=(int& res, const Flight& flight) 
    {
        res += flight.getFlightPassengers();
        return res;
    }

    Flight& Flight::operator<<(Flight& flight)
    {
        if (m_passengers > 0 && flight.m_passengers > 0 && m_passengers <= Boen747Capacity && flight.m_passengers <= Boen747Capacity && m_fuel > 0 && flight.m_fuel > 0 && m_fuel <= FuelTankCapacity && flight.m_fuel <= FuelTankCapacity)
        {
            if (m_passengers + flight.m_passengers <= Boen747Capacity)
            {
                m_passengers += flight.m_passengers;
                flight.m_passengers = 0;
            }
            else if (m_passengers + flight.m_passengers > Boen747Capacity)
            {
                while (flight.m_passengers > 0 && m_passengers < Boen747Capacity)
                {
                    flight.m_passengers--;
                    m_passengers++;
                }
            }
        }

        return *this;
    }

    Flight& Flight::operator>>(Flight& flight)
    {
        if (m_passengers > 0 && flight.m_passengers > 0 && m_passengers <= Boen747Capacity && flight.m_passengers <= Boen747Capacity && m_fuel > 0 && flight.m_fuel > 0 && m_fuel <= FuelTankCapacity && flight.m_fuel <= FuelTankCapacity)
        {
            if (m_passengers + flight.m_passengers <= Boen747Capacity)
            {
                flight.m_passengers += m_passengers;
                m_passengers = 0;
            }
            else if (m_passengers + flight.m_passengers > Boen747Capacity)
            {
                while (m_passengers > 0 && flight.m_passengers < Boen747Capacity)
                {
                    m_passengers--;
                    flight.m_passengers++;
                }
            }
        }

        return *this;
    }

    int Flight::getFlightPassengers() const 
    {
        return m_passengers;
    }

    double Flight::getFlightFuel() const 
    {
        return m_fuel;
    }
}
/*
    ==================================================
    Flights Management
    ==================================================
*/

#ifndef SDDS_FLIGHT_H 
#define SDDS_FLIGHT_H

namespace sdds 
{
    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight 
    {
        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator=(Flight& flight);
        Flight& operator=(const int numOfPassengers);
        Flight& operator=(const double fuel);
        Flight& operator +=(double value);
        Flight& operator+=(int value);
        Flight& operator-=(double value);
        Flight& operator-=(int value);
        Flight& operator<<(Flight& flight);
        Flight& operator>>(Flight& flight);
        int getFlightPassengers() const;
        double getFlightFuel() const;
    };

    int operator+(const Flight& flight1, const Flight& flight2);
    int operator+=(int& res, const Flight& flight);
}

#endif

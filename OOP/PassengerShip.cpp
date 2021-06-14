#include "PassengerShip.h"

    PassengerShip::PassengerShip(double WaterDisplacement , double EnginePower , string Name, string HomePort , int CrewNumber , int NumberOfPassengers , int NumberOfBoats, int BoatCapacity)
        :Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_NumberOfPassengers(NumberOfPassengers), m_NumberOfBoats(NumberOfBoats), m_BoatCapacity(BoatCapacity)
    {
    }
     PassengerShip::~PassengerShip()
    {
        cout << "Удаляем корабль " << this->GetName() << endl;
    }
    bool PassengerShip::EnoughBoats()
    {
        if ((GetCrewNumber() + m_NumberOfPassengers) > (m_NumberOfBoats * m_BoatCapacity))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
     int PassengerShip::IncreaseBoatsNumber() 
    {
        int PeopleWithoutSeats = (m_NumberOfPassengers + GetCrewNumber()) - (m_NumberOfBoats * m_BoatCapacity);
        int MissingBoats = PeopleWithoutSeats / m_BoatCapacity;
        if (PeopleWithoutSeats % m_BoatCapacity != 0)
        {
            MissingBoats++;
        }
        m_NumberOfBoats += MissingBoats;
        return MissingBoats;
    }

     void PassengerShip::Info() const
     {
         Ship::Info();
         cout << "На пассажирском корабле находятся " << m_NumberOfPassengers << " пассажира, и корабль оснащён " << m_NumberOfBoats << " лодками вместимостью по " << m_BoatCapacity << " человек каждая." << endl;
     }

    
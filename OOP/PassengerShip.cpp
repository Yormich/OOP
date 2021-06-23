#include "PassengerShip.h"

    PassengerShip::PassengerShip(double WaterDisplacement , double EnginePower , string Name, string HomePort , int CrewNumber , int NumberOfPassengers , int NumberOfBoats, int BoatCapacity)
        :Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_NumberOfPassengers(NumberOfPassengers), m_NumberOfBoats(NumberOfBoats), m_BoatCapacity(BoatCapacity)
    {
    }
     PassengerShip::~PassengerShip()
    {
        cout << "Destroying passenger ship named " << this->GetName() << endl;
    }
     void PassengerShip::ErrorCheck() const
     {
         Ship::ErrorCheck();
         if (m_NumberOfPassengers < 0 || m_NumberOfBoats < 0 || m_BoatCapacity < 0 || m_BoatCapacity > 50 || m_NumberOfPassengers > 3000 || m_NumberOfBoats > 1000)
         {
             throw exception();
         }
     }
    bool PassengerShip::EnoughBoats() const
    {
        if ((GetCrewNumber() + m_NumberOfPassengers) <= (m_NumberOfBoats * m_BoatCapacity))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     int PassengerShip::IncreaseBoatsNumber() 
    {
         if (EnoughBoats())
         {
             return 0;
         }
         else
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
    }

    void PassengerShip::Info() const
     {
         Ship::Info();
         cout << "On the passenger ship there are " << m_NumberOfPassengers << " passenger, and the ship is equipped" << m_NumberOfBoats << " boats with a capacity of" << m_BoatCapacity << " person each." << endl;
     }

    
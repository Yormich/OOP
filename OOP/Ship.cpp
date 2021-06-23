#include "Ship.h"
  
    Ship::Ship(double WaterDisplacement, double EnginePower, string Name, string HomePort, int CrewNumber)
        :m_Displacement(WaterDisplacement), m_EnginePower(EnginePower), m_Name(Name), m_HomePort(HomePort), m_NumberOfCrew(CrewNumber)
    {
    }

    int Ship::GetCrewNumber() const
    {
        return m_NumberOfCrew;
    }

    void Ship::SetEnginePower(double EnginePower)
    {
        m_EnginePower = EnginePower;
    }

    void Ship::SetWaterDisplacement(double WaterDisplacement)
    {
        m_Displacement = WaterDisplacement;
    }

    void Ship::SetCrewNumber(double CrewNumber)
    {
        m_NumberOfCrew = CrewNumber;
    }

    string Ship::GetName() const
    {
        return m_Name;
    }

    Ship::~Ship()
    {
    }

    void Ship::ErrorCheck() const
    {
        if (m_Displacement < 0 || m_EnginePower < 0 || m_NumberOfCrew < 0 || m_Displacement > 20000 || m_EnginePower > 20000 || m_NumberOfCrew > 2000)
        {
            throw exception();
        }
    }

    void Ship::Info() const
    {
        
        cout << "Ship named " << m_Name << " has " << m_Displacement << " displacement, " << m_EnginePower << " engine power, " << m_NumberOfCrew << " crew and spelled out in " << m_HomePort << "." << endl;
    }
    
#include "Ship.h"

    Ship::Ship():m_Displacement(19876.12), m_EnginePower(13200.5), m_Name("Aurora"), m_HomePort("Odessa"), m_NumberOfCrew(711)
    {
    }
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

    void Ship::Info() const
    {
        
        cout << "Корабль с именем " << m_Name << " имеет " << m_Displacement << " водоизмещение, " << m_EnginePower << " мощность двигателя, " << m_NumberOfCrew << " членов экипажа и основан в " << m_HomePort << "." << endl;
    }
    
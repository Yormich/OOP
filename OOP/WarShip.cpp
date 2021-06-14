#include "WarShip.h"

WarShip:: WarShip(double WaterDisplacement , double EnginePower , string Name , string HomePort , int CrewNumber, TypeOfWeapon gun)
        : Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_Weapon(static_cast<TypeOfWeapon>(rand() % 5))
    {
    }



void WarShip::Info() const
{
    Ship::Info();
    cout << "Военный корабль вооружён " << m_Weapon << "." << endl;
}




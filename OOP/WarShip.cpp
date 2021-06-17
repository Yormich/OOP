#include "WarShip.h"

WarShip:: WarShip(double WaterDisplacement , double EnginePower , string Name , string HomePort , int CrewNumber, TypeOfWeapon gun)
        : Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_Weapon(static_cast<TypeOfWeapon>(rand() % 4))
    {
    }

bool WarShip::AttackOtherShips(int MightOfEnemyShips) const
{
    int PowerOfWeapon;
    int PowerOfCrew = 2;
    switch (m_Weapon)
    {
    case MachineGuns:
        PowerOfWeapon = 450;
        break;
    case Missiles:
        PowerOfWeapon = 1000;
        break;
    case UnderwaterMines:
        PowerOfWeapon = 700;
        break;
    case Mortar:
        PowerOfWeapon = 550;
        break;
    }
    int PowerOfWarShip = PowerOfWeapon + (GetCrewNumber() *PowerOfCrew);
    if (PowerOfWarShip > MightOfEnemyShips)
    {
        return true;
    }
    else
    {
        return false;
    }
}

WarShip::~WarShip()
{
    cout << "Destroying WarShip named " << this->GetName() << endl;
}



void WarShip::Info() const
{
    Ship::Info();
    cout << "The warship is armed ";
    switch (m_Weapon)
    {
        case MachineGuns:
            cout << "by machineguns" << "." << endl;
            break;
        case Missiles:
            cout << "by missilies" << "." << endl;
            break;
        case UnderwaterMines:
            cout << "by underwater mines" << "." << endl;
            break;
        case Mortar:
            cout << "by mortars" << "." << endl;
            break;
    }
}




#pragma once
#include "Ship.h"

enum TypeOfWeapon
{
    MachineGuns,
    Missiles,
    UnderwaterMines,
    Mortar,
    MaxTypesOfGuns
};
class WarShip :public Ship
{   
private:
    TypeOfWeapon m_Weapon;
public:
    WarShip(double WaterDisplacement = 0.0, double EnginePower = 0.0, string Name = "", string HomePort = "", int CrewNumber = 0,TypeOfWeapon = MachineGuns);

    bool AttackOtherShips(int Might) const;

    virtual ~WarShip();

    virtual void Info() const override;
};


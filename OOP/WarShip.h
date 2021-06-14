#pragma once
#include "Ship.h"

enum TypeOfWeapon
{
    MachineGuns,
    Missiles,
    AntiAircraftGuns,
    UnderwaterMines,
    GunMount,
    MaxTypesOfGuns
};
class WarShip :public Ship
{   
private:
    TypeOfWeapon m_Weapon;
public:
    WarShip(double WaterDisplacement = 0.0, double EnginePower = 0.0, string Name = "", string HomePort = "", int CrewNumber = 0,TypeOfWeapon = MachineGuns);



    virtual void Info() const override;
};


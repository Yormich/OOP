#pragma once
#include "Ship.h"

class CargoShip :public Ship
{
private:
    int m_CarryingCapacity;
    int m_RemainingCapacity;
public:
    CargoShip(double WaterDisplacement = 0.0, double EnginePower = 0.0, string Name = "", string HomePort = "", int CrewNumber = 0, double CarryingCapacity = 0);
   
    int AddCargo(int weight);

    int GetRemainingCapacity() const;

    virtual ~CargoShip();

    virtual void ErrorCheck() const override;

    void Info() const override;
};


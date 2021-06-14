#pragma once
#include "Ship.h"

class CargoShip : public Ship
{
private:
    double m_CarryingCapacity;
public:
    CargoShip(double WaterDisplacement = 0.0, double EnginePower = 0.0, string Name = "", string HomePort = "", int CrewNumber = 0, double CarryingCapacity = 0);
   
 


};


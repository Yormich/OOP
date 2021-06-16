#include "CargoShip.h"

CargoShip::CargoShip(double WaterDisplacement, double EnginePower, string Name, string HomePort, int CrewNumber, double CarryingCapacity)
    :Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_CarryingCapacity(CarryingCapacity), m_RemainingCapacity(CarryingCapacity)
    {
    }

double CargoShip::AddCargo(double Cargo)
{
    m_RemainingCapacity -= Cargo;
    return GetRemainingCapacity();
}

double CargoShip::GetRemainingCapacity() const
{
    return m_RemainingCapacity;
}



 
    
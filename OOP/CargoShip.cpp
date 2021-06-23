#include "CargoShip.h"

CargoShip::CargoShip(double WaterDisplacement, double EnginePower, string Name, string HomePort, int CrewNumber, double CarryingCapacity)
    :Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_CarryingCapacity(CarryingCapacity), m_RemainingCapacity(CarryingCapacity)
    {
    }

int CargoShip::AddCargo(int Cargo)
{
    m_RemainingCapacity -= Cargo;
    return GetRemainingCapacity();
}

int CargoShip::GetRemainingCapacity() const
{
    return m_RemainingCapacity;
}

CargoShip::~CargoShip()
{
    cout << "Destroying the cargo ship named " << this->GetName() << endl;
}

void CargoShip::ErrorCheck() const
{
    Ship::ErrorCheck();
    if (m_CarryingCapacity > 50000 || m_RemainingCapacity < 0 || m_CarryingCapacity < 0)
    {
        throw exception();
    }
}

void CargoShip::Info() const
{
    Ship::Info();
    cout << "Also, the cargo ship has a carrying capacity of " << m_CarryingCapacity << " points and remaining capacity of " << m_RemainingCapacity << " points. " << endl;
}





 
    
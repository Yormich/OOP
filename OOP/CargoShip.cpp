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

void CargoShip::Info() const
{
    Ship::Info();
    cout << "Also, the cargo ship has a carrying capacity of " << m_CarryingCapacity << " points." << endl;
}





 
    
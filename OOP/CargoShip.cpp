#include "CargoShip.h"

    CargoShip::CargoShip(double WaterDisplacement, double EnginePower , string Name , string HomePort , int CrewNumber , double CarryingCapacity)
        :Ship(WaterDisplacement, EnginePower, Name, HomePort, CrewNumber), m_CarryingCapacity(CarryingCapacity)
    {
    }
 
    
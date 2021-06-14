#pragma once
#include "Ship.h"

class PassengerShip : public Ship
{
private:
    int m_NumberOfPassengers;
    int m_NumberOfBoats;
    int m_BoatCapacity;
public:
    PassengerShip(double WaterDisplacement = 0.0, double EnginePower = 0.0, string Name = "", string HomePort = "", int CrewNumber = 0, int NumberOfPassengers = 0, int NumberOfBoats = 0, int BoatCapacity = 0);

    virtual ~PassengerShip();

    bool EnoughBoats();

    int IncreaseBoatsNumber();

    virtual void Info() const override;
};
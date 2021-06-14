#pragma once

#include <iostream>
#include <string>
using namespace std;

class Ship
{
private:
    double m_Displacement;
    double m_EnginePower;
    string m_Name;
    int m_NumberOfCrew;
    string m_HomePort;
public:
    Ship();
    
    Ship(double WaterDisplacement, double EnginePower, string Name, string HomePort, int CrewNumber);

    int GetCrewNumber();

    void SetEnginePower(double EnginePower);
    
    void SetWaterDisplacement(double WaterDisplacement);

    void SetCrewNumber(double CrewNumber);

    string GetName();

    virtual ~Ship();
  
   virtual void Info() const;

};

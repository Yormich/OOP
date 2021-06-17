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
    
    Ship(double WaterDisplacement, double EnginePower, string Name, string HomePort, int CrewNumber);

    int GetCrewNumber() const;

    void SetEnginePower(double EnginePower);
    
    void SetWaterDisplacement(double WaterDisplacement);

    void SetCrewNumber(double CrewNumber);

    string GetName() const;

    virtual ~Ship();
  
   virtual void Info() const;

};

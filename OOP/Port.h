#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "Ship.h"
using namespace std;

class Port
{
public:
    void AddShip(Ship* ship);

    void ModifyShip(int pos,int option, int number);

    void ShowShips() const;
   
    void DeleteShip(int pos);

    bool IsEmpty() const;

    virtual ~Port();
   
private:
    vector<Ship*> m_Port;
};


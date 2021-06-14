#include "Port.h"

    void Port::AddShip(Ship* Ship)
    {
        m_Port.push_back(Ship);
    }

    void Port::ModifyShip(int pos, int option, int number)
    {
        switch (option)
        {
            case 1:
                m_Port[pos - 1]->SetEnginePower(number);
                break;
            case 2:
                m_Port[pos - 1]->SetWaterDisplacement(number);
                break;
            case 3:
                m_Port[pos - 1]->SetCrewNumber(number);
        }
    }

    void Port::ShowShips()
    {
        int pos = 1;       
        for (auto Ship : m_Port)
        {
            cout << pos << " - ";
            Ship->Info();
            cout << endl;
            pos++;
        }
    }

    Port::~Port()
    {
        for (auto Ship : m_Port)
        {
            delete[] Ship;
        }
    }

    void Port::DeleteShip(int pos)
    {
        auto iter = m_Port.begin();
        m_Port.erase(iter + pos-1);
    }
    

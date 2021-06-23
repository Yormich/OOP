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

    void Port::ShowShips() const
    {
        int pos = 1;       
        for (auto ship : m_Port)
        {
            cout << pos << " - ";
            ship->Info();
            cout << endl;
            pos++;
        }
    }

    Port::~Port()
    {
        for (auto ship : m_Port)
        {
            delete ship;
        }
    }

    void Port::DeleteShip(int pos)
    {
        auto iter = m_Port.begin();
        delete m_Port.at(pos - 1);
        m_Port.erase(iter + pos-1);
    }

    bool Port::IsEmpty() const
    {
        if (m_Port.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    

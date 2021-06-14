#include "Console Menu.h"
#include "WarShip.h"
#include "CargoShip.h"
#include "PassengerShip.h"
#include "Port.h"

void PrintMainMenu()
{
    cout << " �������� ���������� �����:" << endl;
    cout << "|  1 - ������� �������.        |" << endl;
    cout << "|  2 - �������������� �������. |" << endl;
    cout << "|  3 - ����������� �������.    |" << endl;
    cout << "|  4 - ������� �������.        |" << endl;
    cout << "|  5 - ��������� ������.       |" << endl;
}

int GetOption(int OptionsCount)
{
    int variant;
    string input;
    cin >> input;
    while (stoi(input) < 1 || stoi(input) > OptionsCount)
    {
        cout << "�������� ����, ��������� �������." << endl;
        input.clear();
        cin >> input;
    }
    variant = stoi(input);
    return variant;
}


void CreateShipMenu(Port& port)
{
    cout << "�������� ��� �������, ������� �� ������ ��������: " << endl;
    cout << "|  1 - ������������ �������.  |" << endl;
    cout << "|  2 - �������� �������.      |" << endl;
    cout << "|  3 - ������� �������.       |" << endl;
    double Displacement;
    double EnginePower;
    string Name;
    int NumberOfCrew;
    string HomePort;
    int NumberOfPassengers;
    int NumberOfBoats;
    int BoatCapacity;
    double CarryingCapacity;
    TypeOfWeapon Weapon;
    int options = 3;
    int	variant = GetOption(options);
    Ship* ptr = nullptr;
    switch (variant)
    {

    case 1:
        cout << "������� �������������." << endl;
        cin >> Displacement;
        cout << "������� �������� ���������." << endl;
        cin >> EnginePower;
        cout << "������� ��� �������." << endl;
        cin >> Name;
        cout << "������� ���������� ������ �������." << endl;
        cin >> NumberOfCrew;
        cout << "������� �������� ����." << endl;
        cin >> HomePort;
        cout << "B������ ���������� ����������." << endl;
        cin >> NumberOfPassengers;
        cout << "������� ���������� ������." << endl;
        cin >> NumberOfBoats;
        cout << "������� ����������� ������." << endl;
        cin >> BoatCapacity;
        ptr = new PassengerShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, NumberOfPassengers, NumberOfBoats, BoatCapacity);
        port.AddShip(ptr);
        break;
    case 2:
        cout << "������� �������������." << endl;
        cin >> Displacement;
        cout << "������� �������� ���������." << endl;
        cin >> EnginePower;
        cout << "������� ��� �������." << endl;
        cin >> Name;
        cout << "������� ���������� ������ �������." << endl;
        cin >> NumberOfCrew;
        cout << "������� �������� ����." << endl;
        cin >> HomePort;
        cout << "������� ���������������� �������" << endl;
        cin >> CarryingCapacity;
        ptr = new CargoShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, CarryingCapacity);
        port.AddShip(ptr);
        break;
    case 3:
        cout << "������� �������������." << endl;
        cin >> Displacement;
        cout << "������� �������� ���������." << endl;
        cin >> EnginePower;
        cout << "������� ��� �������." << endl;
        cin >> Name;
        cout << "������� ���������� ������ �������." << endl;
        cin >> NumberOfCrew;
        cout << "������� �������� ����." << endl;
        cin >> HomePort;
        Weapon = static_cast<TypeOfWeapon>(rand() % 5);
        ptr = new WarShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, Weapon);
        port.AddShip(ptr);
        break;
    }
 
}

void ModifyShipsMenu(Port& port)
{
    port.ShowShips();
    pair<int, int> Modify;
    cout << "�������� ������� ��� �����������: " << endl;
    int ShipPos;
    cin >> ShipPos;
    Modify.first = ShipPos;
    cout << "��������, ��� �� ������ ��������: " << endl;
    cout << "|  1 - �������� ���������        |" << endl;
    cout << "|  2 - �������������             |" << endl;
    cout << "|  3 - ���������� ������ ������� |" << endl;
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
            int EnginePower;
            cout << "������� �������� �������� ���������: " << endl;
            cin >> EnginePower;
            port.ModifyShip(ShipPos, option, EnginePower);
            break;
        case 2:
            int WaterDisplacement;
            cout << "������� ����� �������������: " << endl;
            cin >> WaterDisplacement;
            port.ModifyShip(ShipPos, option,WaterDisplacement);
            break;
        case 3:
            int CrewNumber;
            cout << "������� ����� ��������� ������ �������: " << endl;
            cin >> CrewNumber;
            port.ModifyShip(ShipPos, option,CrewNumber);
            break;
    }

}

void DeleteShipsMenu(Port& port)
{
    port.ShowShips();
    cout << "�������� ������� ��� ��������: " << endl;
    int ShipPos;
    cin >> ShipPos;
    port.DeleteShip(ShipPos);
}

void ShowShipsMenu(Port& port)
{
    port.ShowShips();
}

void ConsoleMenu()
{
    
    int variant;
    Port A;
    do
    {
        PrintMainMenu();
        int OptionsCount = 5;
        variant = GetOption(OptionsCount);
        switch (variant)
        {
        case 1:
            CreateShipMenu(A);
            break;
        case 2:
            ModifyShipsMenu(A);
            break;
        case 3:
            ShowShipsMenu(A);
            break;
        case 4:
            DeleteShipsMenu(A);
            break;
        }
        if (variant != 5)
        {
            system("pause");
        }
    } while (variant != 5);
}

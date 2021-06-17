#include "Console Menu.h"
#include "WarShip.h"
#include "CargoShip.h"
#include "PassengerShip.h"
#include "Port.h"
using namespace std;

void PrintMainMenu()
{
    cout << "Select further option: " << endl;
    cout << "|  1 - Create a ship.     |" << endl;
    cout << "|  2 - Modify the ship.   |" << endl;
    cout << "|  3 - View ships.        |" << endl;
    cout << "|  4 - Remove the ship.   |" << endl;   
    cout << "|  5 - Complete the work. |" << endl;
}

int GetOption(int OptionsCount)
{
    int variant;
    string input;
    cin >> input;
    while (stoi(input) < 1 || stoi(input) > OptionsCount)
    {
        cout << "Invalid entry, please try again." << endl;
        input.clear();
        cin >> input;
    }
    variant = stoi(input);
    return variant;
}


void CreateShipMenu(Port& port)
{
    cout << "Select the type of ship you want to add: " << endl;
    cout << "|  1 - Passenger ship. |" << endl;
    cout << "|  2 - Cargo ship.     |" << endl;
    cout << "|  3 - Warship.        |" << endl;
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
    PassengerShip* ps = nullptr;
    CargoShip* cs = nullptr;
    WarShip* ws = nullptr;
    int options = 3;
    int	variant = GetOption(options);
    int MissingBoats;// для пассажирского корабля.
    int input; // для военного и грузового корабля.
    double Cargo;//для грузового корабля
    int MightOfEnemyShips; // для военного корабля
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> DistForEnShips(1, 4);
    uniform_int_distribution<int> DistForPowerOfEnShips(1, 250);
    uniform_int_distribution<int> DistForWeapon(0, 3);
    switch (variant)
    {
    case 1:
        cout << "Enter the displacement." << endl;
        cin >> Displacement;
        cout << "Enter the engine power." << endl;
        cin >> EnginePower;
        cout << "Enter the name of the ship." << endl;
        cin >> Name;
        cout << "Enter the number of crew members." << endl;
        cin >> NumberOfCrew;
        cout << "Enter home port." << endl;
        cin >> HomePort;
        cout << "Enter the number of passengers." << endl;
        cin >> NumberOfPassengers;
        cout << "Enter the number of boats." << endl;
        cin >> NumberOfBoats;
        cout << "Enter the capacity of the boats." << endl;
        cin >> BoatCapacity;
        if (Displacement < 0 || EnginePower < 0 || NumberOfCrew < 0 || NumberOfPassengers < 0 || NumberOfBoats < 0 << BoatCapacity < 0)
        {
            throw exception();
        }
        ps = new PassengerShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, NumberOfPassengers, NumberOfBoats, BoatCapacity);
        port.AddShip(ps);
        MissingBoats = ps->IncreaseBoatsNumber();
        if (MissingBoats == 0)
        {
            cout << "The number of boats is enough for passengers and crew." << endl;
        }
        else
        {
            cout << "The number of boats was not enough for passengersand crew.It was increased by " << MissingBoats << " boats." << endl;
        }
        break;
    case 2:      
        cout << "Enter the displacement." << endl;
        cin >> Displacement;
        cout << "Enter the engine power." << endl;
        cin >> EnginePower;
        cout << "Enter the name of the ship." << endl;
        cin >> Name;
        cout << "Enter the number of crew members." << endl;
        cin >> NumberOfCrew;
        cout << "Enter home port." << endl;
        cin >> HomePort;
        cout << "Enter the cargo capacity of the ship " << endl;
        cin >> CarryingCapacity;
        if (Displacement < 0 || EnginePower < 0 || NumberOfCrew < 0 || CarryingCapacity<0)
        {
            throw exception();
        }
        cs = new CargoShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, CarryingCapacity);
        port.AddShip(cs);
        cout << "Do you want to add cargo to the ship? 1 - Yes, 2 - No." << endl;
        cin >> input;
        while (input != 2|| input >2 || input <1)
        {
            cout << "Enter the approximate weight of the shipment you want to add to " << cs->GetName() << ", it should not exceed ";
            cout << cs->GetRemainingCapacity() << "." << endl;
            cin >> Cargo;
            if (cs->AddCargo(Cargo) >= 0)
            {
                cout << "Remaining capacity: " << cs->GetRemainingCapacity() << "." << endl;
            }
            else
            {
                throw exception();
            }
            cout << "Do you want to add cargo to the ship? 1 - Yes, 2 - No." << endl;      
            cin >> input;
        }
        break;
    
    case 3:     
        cout << "Enter the displacement." << endl;
        cin >> Displacement;
        cout << "Enter the engine power." << endl;
        cin >> EnginePower;
        cout << "Enter the name of the ship." << endl;
        cin >> Name;
        cout << "Enter the number of crew members." << endl;
        cin >> NumberOfCrew;
        cout << "Enter home port." << endl;
        cin >> HomePort;
        if (Displacement < 0 || EnginePower < 0 || NumberOfCrew < 0)
        {
            throw exception();
        }
        Weapon = static_cast<TypeOfWeapon>(DistForWeapon(mt));
        ws= new WarShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, Weapon);
        port.AddShip(ws);
        MightOfEnemyShips = (DistForEnShips(mt) * DistForPowerOfEnShips(mt));
        cout << "An enemy fleet was discovered nearby with an approximate firepower of" << MightOfEnemyShips << "." << endl;
        cout << "Information about your ship: " << endl;
        ws->Info();
        cout << "Do you want to make an attack? 1 - Yes, 2 - No." << endl;
        cin >> input;
        if (input == 1)
        {
            if (ws->AttackOtherShips(MightOfEnemyShips))
            {
                cout << "The attack ended successfully, the enemy's fleet was defeated. " << endl;
            }
            else
            {
                cout << "The attack failed unexpectedly, and your ship had to retreat. " << endl;
            }
        }
        break;
    }
 
}

void ModifyShipsMenu(Port& port)
{
    port.ShowShips();
    cout << "Select a ship for modification: " << endl;
    int ShipPos;
    cin >> ShipPos;
    cout << "Choose what you want to change: " << endl;
    cout << "|  1 - Engine power           |" << endl;
    cout << "|  2 - Displacement           |" << endl;
    cout << "|  3 - Number of crew members |" << endl;
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
            int EnginePower;
            cout << "Enter the desired engine power: " << endl;
            cin >> EnginePower;
            port.ModifyShip(ShipPos, option, EnginePower);
            break;
        case 2:
            int WaterDisplacement;
            cout << "Enter the new displacement: " << endl;
            cin >> WaterDisplacement;
            port.ModifyShip(ShipPos, option,WaterDisplacement);
            break;
        case 3:
            int CrewNumber;
            cout << "Enter the new number of crew members: " << endl;
            cin >> CrewNumber;
            port.ModifyShip(ShipPos, option,CrewNumber);
            break;
    }

}

void DeleteShipsMenu(Port& port)
{
    port.ShowShips();
    cout << "Select a ship to delete : " << endl;
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
        try
        {
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
        }
        catch (const exception&)
        {
            cout << "You made an incorrect input, please try again" << endl;
        }
    } while (variant != 5);
}

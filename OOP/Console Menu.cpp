#include "Console Menu.h"
#include "WarShip.h"
#include "CargoShip.h"
#include "PassengerShip.h"
#include "Port.h"

void PrintMainMenu()
{
    cout << " Выберите дальнейшую опцию:" << endl;
    cout << "|  1 - Создать корабль.        |" << endl;
    cout << "|  2 - Модифицировать корабль. |" << endl;
    cout << "|  3 - Просмотреть корабли.    |" << endl;
    cout << "|  4 - Удалить корабль.        |" << endl;
    cout << "|  5 - Завершить работу.       |" << endl;
}

int GetOption(int OptionsCount)
{
    int variant;
    string input;
    cin >> input;
    while (stoi(input) < 1 || stoi(input) > OptionsCount)
    {
        cout << "Неверный ввод, повторите попытку." << endl;
        input.clear();
        cin >> input;
    }
    variant = stoi(input);
    return variant;
}


void CreateShipMenu(Port& port)
{
    cout << "Выберите тип корабля, который вы хотите добавить: " << endl;
    cout << "|  1 - Пассажирский корабль.  |" << endl;
    cout << "|  2 - Грузовой корабль.      |" << endl;
    cout << "|  3 - Военный корабль.       |" << endl;
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
        cout << "Введите водоизмещение." << endl;
        cin >> Displacement;
        cout << "Введите мощность двигателя." << endl;
        cin >> EnginePower;
        cout << "Введите имя корабля." << endl;
        cin >> Name;
        cout << "Введите количество членов экипажа." << endl;
        cin >> NumberOfCrew;
        cout << "Введите домашний порт." << endl;
        cin >> HomePort;
        cout << "Bведите количество пассажиров." << endl;
        cin >> NumberOfPassengers;
        cout << "Введите количество шлюпок." << endl;
        cin >> NumberOfBoats;
        cout << "Введите вместимость шлюпок." << endl;
        cin >> BoatCapacity;
        ptr = new PassengerShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, NumberOfPassengers, NumberOfBoats, BoatCapacity);
        port.AddShip(ptr);
        break;
    case 2:
        cout << "Введите водоизмещение." << endl;
        cin >> Displacement;
        cout << "Введите мощность двигателя." << endl;
        cin >> EnginePower;
        cout << "Введите имя корабля." << endl;
        cin >> Name;
        cout << "Введите количество членов экипажа." << endl;
        cin >> NumberOfCrew;
        cout << "Введите домашний порт." << endl;
        cin >> HomePort;
        cout << "Введите грузоподъёмность корабля" << endl;
        cin >> CarryingCapacity;
        ptr = new CargoShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, CarryingCapacity);
        port.AddShip(ptr);
        break;
    case 3:
        cout << "Введите водоизмещение." << endl;
        cin >> Displacement;
        cout << "Введите мощность двигателя." << endl;
        cin >> EnginePower;
        cout << "Введите имя корабля." << endl;
        cin >> Name;
        cout << "Введите количество членов экипажа." << endl;
        cin >> NumberOfCrew;
        cout << "Введите домашний порт." << endl;
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
    cout << "Выберите корабль для модификации: " << endl;
    int ShipPos;
    cin >> ShipPos;
    Modify.first = ShipPos;
    cout << "Выберите, что вы хотите изменить: " << endl;
    cout << "|  1 - Мощность двигателя        |" << endl;
    cout << "|  2 - Водоизмещение             |" << endl;
    cout << "|  3 - Количество членов экипажа |" << endl;
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
            int EnginePower;
            cout << "Введите желаемую мощность двигателя: " << endl;
            cin >> EnginePower;
            port.ModifyShip(ShipPos, option, EnginePower);
            break;
        case 2:
            int WaterDisplacement;
            cout << "Введите новое водоизмещение: " << endl;
            cin >> WaterDisplacement;
            port.ModifyShip(ShipPos, option,WaterDisplacement);
            break;
        case 3:
            int CrewNumber;
            cout << "Введите новое колиество членов экипажа: " << endl;
            cin >> CrewNumber;
            port.ModifyShip(ShipPos, option,CrewNumber);
            break;
    }

}

void DeleteShipsMenu(Port& port)
{
    port.ShowShips();
    cout << "Выберите корабль для удаления: " << endl;
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

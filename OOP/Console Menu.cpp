#include "Console Menu.h"
#include "WarShip.h"
#include "CargoShip.h"
#include "PassengerShip.h"
#include "Port.h"
using namespace std;

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
    uniform_int_distribution<int> DistForEnShips(1,4);
    uniform_int_distribution<int> DistForPowerOfEnShips(1, 250);
    uniform_int_distribution<int> DistForWeapon(0,3);
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
        ps = new PassengerShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, NumberOfPassengers, NumberOfBoats, BoatCapacity);
        port.AddShip(ps);
        MissingBoats = ps->IncreaseBoatsNumber();
        if (MissingBoats == 0)
        {
            cout << "Количества лодок хватает на пассажиров и экипаж." << endl;
        }
        else
        {
            cout << "Количества лодок не хватило на пассажиров и экипаж.Оно было увеличено на " << MissingBoats << " лодок." << endl;
        }
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
        cs = new CargoShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, CarryingCapacity);
        port.AddShip(cs);
        cout << "Хотите ли вы добавить груз на корабль?1 - Да, 2 - Нет." << endl;
        cin >> input;
        while (input != 2||(input >2 && input <1))
        {
            cout << "Введите приблизительный вес груза, который вы хотите добавить на " << cs->GetName() << ", он не должен превышать ";
            cout << cs->GetRemainingCapacity() << "." << endl;
            cin >> Cargo;
            if (cs->AddCargo(Cargo) > 0)
            {
                cout << "Оставшееся кол-во грузоподъёмности: " << cs->AddCargo(Cargo) << "." << endl;
            }
            else
            {
                throw exception();
            }
            cout << "Хотите ли вы добавить груз на корабль?1 - Да, 2 - Нет." << endl;      
            cin >> input;
        }
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
        Weapon = static_cast<TypeOfWeapon>(DistForWeapon(mt));
        ws= new WarShip(Displacement, EnginePower, Name, HomePort, NumberOfCrew, Weapon);
        port.AddShip(ws);
        MightOfEnemyShips = (DistForEnShips(mt) * DistForPowerOfEnShips(mt));
        cout << "Поблизости обнаружился флот врага с примерной огневой мощью в " << MightOfEnemyShips << "." << endl;
        cout << "Информация и вашем корабле: " << endl;
        ws->Info();
        cout << "Хотите ли вы совершить атаку? 1 - Да, 2 - Нет." << endl;
        cin >> input;
        if (input == 1)
        {
            if (ws->AttackOtherShips(MightOfEnemyShips))
            {
                cout << "Атака закончилась успешно, флот противника разгромлен." << endl;
            }
            else
            {
                cout << "Атака непредвиденно обернулась неудачей, вашему кораблю пришлось отступить." << endl;
            }
        }
        break;
    }
 
}

void ModifyShipsMenu(Port& port)
{
    port.ShowShips();
    cout << "Выберите корабль для модификации: " << endl;
    int ShipPos;
    cin >> ShipPos;
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
            cout << "Введите новое количество членов экипажа: " << endl;
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
            cout << "Ой, вы создали ошибку в программе..." << endl;
        }
    } while (variant != 5);
}

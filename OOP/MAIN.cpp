﻿#include <iostream>
#include <string>
#include <vector>
#include "Console Menu.h"
using namespace std;

/*Создать иерархию классов: корабль – базовый класс и пассажирский корабль – производный. 
Корабль имеет  мощность двигателя, водоизмещение, название, порт приписки, количество членов экипажа. 
Пассажирский корабль имеет дополнительные поля: количество пассажиров, количество шлюпок, вместимость шлюпки. 
Реализовать метод проверки, что шлюпок хватает на пассажиров и членов экипажа и метод увеличения числа шлюпок до минимально необходимого, если их не хватает.
Также реализовать класс грузовой корабль с дополнительным параметром  – грузоподъемность и военный корабль с дополнительным параметром – вид вооружения.
В основном проекте реализовать создание, модификацию и удаление кораблей, а также добавление шлюпок на пассажирские корабли.
*/

//сделать енум скорее всего в классе порт, который можно реал. в меню , мейби переделать функцию с модифаем.
int main()
{
    setlocale(LC_ALL, "Russian");
    ConsoleMenu();
    return 0;
}
#pragma once
#include <iostream>
#include <string>
#include "Port.h"
#include <random>

void PrintMainMenu();

int GetOption(int OptionsCount);

void ConsoleMenu();

void ModifyShipsMenu(Port& port);

void CreateShipMenu(Port& port);

void ShowShipsMenu(Port& port);

void DeleteShipsMenu(Port &port);


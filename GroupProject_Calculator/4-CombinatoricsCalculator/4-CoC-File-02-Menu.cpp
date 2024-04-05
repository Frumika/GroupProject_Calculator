#include "../0-Common/0-Co-File-01-Header.h"
#include "4-CoC-File-01-Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

void runCombinatoricsCalculator()
{
    char input;

    do
    {
    cout
        << "|------------------------------------------------|" << endl
        << "|    >>> Калькулятор формул комбинаторики <<<    |" << endl
        << "|------------------------------------------------|" << endl
        << "| 1. Размещение с повторениями                   |" << endl
        << "| 2. Размещение без повторений                   |" << endl
        << "| 3. Сочетание с повторениями                    |" << endl
        << "| 4. Сочетание без повторений                    |" << endl
        << "| 5. Перестановки                                |" << endl
        << "| 0. Выйти в главное меню                        |" << endl
        << "|------------------------------------------------|" << endl;
    do
    {
        input = _getch();
    }
    while (
        input != '1' &&
        input != '2' &&
        input != '3' &&
        input != '4' &&
        input != '5' &&
        input != '0'
        );

    switch(input)
    {
    case '1':
        {
            system("cls");
            placementWithRep();
        }
        break;
    case '2':
        {
            system("cls");
            placementWithoutRep();
        }
        break;
    case '3':
        {
            system("cls");
            combinationWithRep();
        }
        break;
    case '4':
        {
            system("cls");
            combinationWithoutRep();
        }
        break;
    case '5':
        {
            system("cls");
            reshuffle();
        }
        break;
    default:
        {
            system("cls");
            runMainMenu();
        }
    }
    }
    while (input != '0');
}
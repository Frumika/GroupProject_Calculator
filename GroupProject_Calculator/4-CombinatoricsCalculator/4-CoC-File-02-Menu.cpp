#include "../0-Common/0-Co-File-01-Header.h"
#include "4-CoC-File-01-Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

void displayCombinatoricsMenu()
{
    char input;

    //Выбор калькулятора
    do
    {
        cout
            << "|------------------------------------------|" << endl
            << "| >>> Калькулятор формул комбинаторики <<< |" << endl
            << "|------------------------------------------|" << endl
            << "| 1. Размещение с повторениями             |" << endl
            << "| 2. Размещение без повторений             |" << endl
            << "| 3. Сочетание с повторениями              |" << endl
            << "| 4. Сочетание без повторений              |" << endl
            << "| 5. Перестановки                          |" << endl
            << "| 0. Выйти в главное меню                  |" << endl
            << "|------------------------------------------|" << endl;
        
        input = _getch();
        system("cls");
    }
    while (             //
        input != '1' && //
        input != '2' && //
        input != '3' && //  Тоже проверка на дурака
        input != '4' && //
        input != '5' && //
        input != '0'    //
        );              //

    switch(input)
    {
        case '1':
            {
                system("cls");
                runPlacementWithRep();
            }
            break;
        case '2':
            {
                system("cls");
                runPlacementWithoutRep();
            }
            break;
        case '3':
            {
                system("cls");
                runCombinationWithRep();
            }
            break;
        case '4':
            {
                system("cls");
                runCombinationWithoutRep();
            }
            break;
        case '5':
            {
                system("cls");
                runReshuffle();
            }
            break;
        default:
            {
                system("cls");
                runMainMenu();
            }
    }
    //Перезапуск калькулятора
    runCombinatoricsCalculator();   //А может всё-таки через do/while???
}

void runCombinatoricsCalculator()
{
    displayCombinatoricsMenu();
}
#include "../0-Common/0-Co-File-01-Header.h"
#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

void diplayProbabilityMenu()
{
    char input;

    //Выбор калькулятора
    do
    {
        cout
            << "|---------------------------------------------------------|" << endl
            << "|    >>> Калькулятор вероятности и мат. статистики <<<    |" << endl
            << "|---------------------------------------------------------|" << endl
            << "| 1. Вероятность m/n                                      |" << endl
            << "| 2. Мат. ожидание для дискретного распределения величин  |" << endl
            << "| 3. Дисперсия для дискретного распределения величин      |" << endl
            << "| 0. Выйти в главное меню                                 |" << endl
            << "|---------------------------------------------------------|" << endl;
        
        input = _getch();
        system("cls");
    }
    while (             //
        input != '1' && //
        input != '2' && //  Тоже проверка на дурака
        input != '3' && //
        input != '0'    //
        );              //

    switch(input)
    {
    case '1':
        {
            system("cls");
            runProbability();
        }
        break;
    case '2':
        {
            system("cls");
            runMathExpectation();
        }
        break;
    case '3':
        {
            system("cls");
            runDispersion();
        }
        break;
    default:
        {
            system("cls");
            runMainMenu();
        }
    }
    //Перезапуск калькулятора
    runProbabilityCalculator();
}

void runProbabilityCalculator()
{
    diplayProbabilityMenu();
}
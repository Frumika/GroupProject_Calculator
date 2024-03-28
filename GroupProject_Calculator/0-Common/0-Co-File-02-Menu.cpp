#include <iostream>
#include <conio.h>
#include "0-Co-File-01-Header.h"

using namespace std;

void runMainMenu()
{
    char button;
    bool condition;

    cout
        << "+------------------------------------------------+" << endl
        << "|              >>> Главное меню <<<              |" << endl
        << "|------------------------------------------------|" << endl
        << "| 1. Матрицный калькулятор                       |" << endl
        << "| 2. Калькулятор обыкновенных дробей             |" << endl
        << "| 3. Калькулятор функций                         |" << endl
        << "| 4. Калькулятор формул комбинаторики            |" << endl
        << "| 5. Калькулятор тер. вероятности и мат. стат.   |" << endl
        << "| 6. Калькулятор многочленов                     |" << endl
        << "| 0. Выйти из программы                          |" << endl
        << "+------------------------------------------------+" << endl;

    do
    {
        button = _getch();
        
        condition = (button == '1' ||
            button == '2' ||
            button == '3' ||
            button == '4' ||
            button == '5' ||
            button == '6' ||
            button == '0');
    }
    while (condition == false);

    
    switch (button)
    {
    case '1':
        {
            system("cls");
            runMatrixCalculator();
        }
        break;
    case '2':
        {
            system("cls");
            runFractionCalculator();
        }
        break;
    case '3':
        {
            system("cls");
            runFunctionCalculator();
        }
        break;
    case '4':
        {
            system("cls");
            runCombinatoricsCalculator();
        }
        break;
    case '5':
        {
            system("cls");
            runProbabilityCalculator();
        }
        break;
    case '6':
        {
            system("cls");
            runPolynomialCalculator();
        }
        break;

    default:
        {
            cout
                << "|------------------------------------------------|" << endl
                << "|      >>> Работа программы завершена <<<        |" << endl
                << "|------------------------------------------------|" << endl;

            exit(0);
        }
    }
}

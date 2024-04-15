#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

/* Калькулятор математического ожидания */
void runMathExpectation()
{
    int arraySize;

    //Ввод количества величин
    do
    {
        cout
            << "|------------------------------------------------|" << endl
            << "|       >>> Калькулятор мат. ожидания <<<        |" << endl
            << "|                >>> Справка <<<                 |" << endl
            << "|                                                |" << endl
            << "| * величин может быть от 2 до 25                |" << endl
            << "| * сумма вероятностей должна равняться 1        |" << endl
            << "|------------------------------------------------|" << endl << endl
            << "Введите количество величин: ", cin >> arraySize;
        if(arraySize < 1)
        {
            cout
                << endl
                << "Величин не может быть меньше 1!" << endl
                << "Нажмите любую клавишу чтобы продолжить...";
            _getch();
            system("cls");
        }
        else if(arraySize > 25)
        {
            cout
                << endl
                << "Величин не может быть больше 25!" << endl
                << "Нажмите любую клавишу чтобы продолжить...";
            _getch();
            system("cls");
        }
    }
    while (arraySize < 1 || arraySize > 25);
    
    double **x = createArray(arraySize);    //Создание двумерного массива
    enterArray(x, arraySize);               //Ввод двумерного массива
    cout << "Математическое ожидание = " << setprecision(numeric_limits<double>::max_digits10) << solveMathExpectation(x, arraySize) << endl << endl;
    deleteArray(x);                         //Удаление двумерного массива

    cout << "Нажмите любую клавишу чтобы продолжить...";    //
    _getch();                                               //Не даёт сразу выйти в меню
    system("cls");
}
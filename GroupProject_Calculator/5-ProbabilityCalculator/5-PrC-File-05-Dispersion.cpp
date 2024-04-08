#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

/* Калькулятор дисперсии */
void runDispersion()
{
    int arraySize;

    //Ввод количества величин
    do
    {
        cout
            << "|-----------------------------------------|" << endl
            << "|             >>> Справка <<<             |" << endl
            << "| *величин может быть от 2 до 25          |" << endl
            << "| *сумма вероятностей должна равняться 1  |" << endl
            << "|-----------------------------------------|" << endl << endl
            << "Введите количество величин: ", cin >> arraySize;
        if(arraySize < 1)
        {
            cout << "Величин не может быть меньше 1!";
            _getch();
        }
        else if(arraySize > 25)
        {
            cout << "Величин не может быть больше 25!";
            _getch();
        }
        system("cls");
    }
    while (arraySize < 1 || arraySize > 25);
    
    double **x = createArray(arraySize);    //Создание двумерного массива
    enterArray(x, arraySize);               //Ввод двумерного массива
    cout << "Дисперсия = " << setprecision(numeric_limits<double>::max_digits10) << solveSquareMathExpectation(x, arraySize)-solveMathExpectation(x, arraySize)*solveMathExpectation(x, arraySize) << endl;
    deleteArray(x);                         //Удаление двумерного массива

    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}
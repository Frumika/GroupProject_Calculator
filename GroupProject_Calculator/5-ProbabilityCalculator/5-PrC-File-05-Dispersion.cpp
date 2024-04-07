#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

void runDispersion()
{
    int arraySize;
    double probabilitySum = 0, dispersion, mathExpectation;
    double **x = new double*[2];    //Массив значений и вероятностей

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
    //Созданаие колонок в массиве
    x[0] = new double[arraySize];
    x[1] = new double[arraySize];
    //Ввод пар значений + вероятностей
    do
    {
        cout << "Введите пары значений + вероятности: ";
        for(int column = 0; column < arraySize; column++)
        {
            double probability;
            cin >> x[0][column] >> probability;
            x[1][column] = probability;
            probabilitySum += probability;
        }
        if(probabilitySum != 1)
        {
            cout
                << "Сумма вероятностей не равна 0!" << endl
                << "Введите пары заново";
            _getch();
        }
        system("cls");
    }
    while (probabilitySum != 1);
    mathExpectation = solveMathExpectation(x, arraySize);                                   //Просчёт математического ожидания
    dispersion = solveSquareMathExpectation(x, arraySize)-mathExpectation*mathExpectation;  //Просчёт дисперсии
    cout
        << "Математическое ожидание = " << setprecision(numeric_limits<double>::max_digits10) << mathExpectation << endl
        << "Дисперсия = " << setprecision(numeric_limits<double>::max_digits10) << dispersion << endl
        << "Стандартное отклонение = ";
    if(dispersion >= 0) cout << setprecision(numeric_limits<double>::max_digits10) << sqrt(dispersion);
    else cout << "NuN";
    
    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}
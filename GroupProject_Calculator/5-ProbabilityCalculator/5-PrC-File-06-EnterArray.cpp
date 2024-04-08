﻿#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

/* Ввод массива */
void enterArray(double **x, int arraySize)
{
    double probabilitySum = 0;
    
    //Ввод пар значений + вероятностей
    do
    {
        cout << "Введите " << arraySize << " пары значений + вероятности: ";
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
}
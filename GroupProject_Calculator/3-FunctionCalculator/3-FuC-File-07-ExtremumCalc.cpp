#include "3-FuC-File-01-Header.h"

#include <iostream>
#include <cmath>

const double goldenRatio = (1 + sqrt(5)) / 2;

double FindExtrem(double st, double en, function<double (double)> ChosenFunc, int mode = 0, double acc = 0.0001)
{
    double x1, x2;
    
    while (abs(en - st) > acc)
    {
        x1 = en - (en - st) / goldenRatio;
        x2 = st + (en - st) / goldenRatio;
        
        if (mode == 0)
        {
            if (ChosenFunc(x1) <= ChosenFunc(x2))
                st = x1;
            else
                en = x2;
        }
        else
        {
            if (ChosenFunc(x1) >= ChosenFunc(x2))
                st = x1;
            else
                en = x2;
        }
    }

    return (st + en) / 2;
}

void runExtremumCalc(function<double (double)> ChosenFunc)
{
    double st, en;
    bool ans;
    
    do
    {
        cout << "Введите границы отрезка: "; cin >> st >> en;
    } while (st >= en);

    cout << "Локальный минимум функции на интервале: " << ChosenFunc(FindExtrem(st, en, ChosenFunc, 1)) << endl;
    cout << "Локальный максимум функции на интервале: " << ChosenFunc(FindExtrem(st, en, ChosenFunc, 0)) << endl;
    
    cout << "\nПродолжить работу с текущей функцией? ";
    
    do
    {
        cin >> ans;
        if (ans != 0 || ans != 1) cout << "Ошибка ввода";
    }
    while (ans != 0 && ans != 1);
    
    if (ans == 1)
    {
        system("cls");
        runSecondFuncMenu(ChosenFunc);
    }
    else
    {
        system("cls");
        runFunctionCalculator();
    }
}


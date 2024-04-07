#include "3-FuC-File-01-Header.h"

double IntegralCalc(double st, double en, int n, function<double (double)> ChosenFunc)
{
    double width = (en - st) / n;
    double sum = ChosenFunc(st) + ChosenFunc(en);
    int k;

    for (int i = 0; i <= n - 1; i++)
    {
        k = 2 + 2 * (i  % 2);
        sum += k * ChosenFunc(st + i * width);
    }
    sum *= width / 3;

    return sum;
}

void runDefIntegral(function<double (double)> ChosenFunc)
{
    double st = 1, en = 0;
    int n = 1000;
    
    do
    {
        cout << "Введите границы отрезка: "; cin >> st >> en;
    } while (st >= en);

    double e = 0.0001;
    int k = 10;
    int i = 0;
    double diff;
    
    do
    {
        i++;
        diff = fabs(IntegralCalc(st, en, k * i, ChosenFunc) - IntegralCalc(st, en, k * (i + 1), ChosenFunc));
    } while (diff > e);

    cout <<  IntegralCalc(st, en, k * (i + 1), ChosenFunc);

    bool ans;
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
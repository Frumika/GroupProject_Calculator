#include "3-FuC-File-01-Header.h"

double FindRoot(double a, double b, double eps, function<double(double)> ChosenFunc)
{
    double mid = (b + a) / 2;
    while (abs(ChosenFunc(mid)) > eps)
    {
        if (ChosenFunc(mid) > 0)
            b = mid;
        else
            a = mid;
        mid = (b + a) / 2;
    }

    return mid;
}

void runFuncRootCalc(function<double(double)> ChosenFunc)
{
    double st, en;
    double eps = 0.0001;

    do
    {
        cout << "Введите границы отрезка: "; cin >> st >> en;
    } while (st > en);

    cout << "Корень уравнения: " << FindRoot(st, en, eps, ChosenFunc) << endl;
}
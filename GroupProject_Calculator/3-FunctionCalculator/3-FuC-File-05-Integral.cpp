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

double runDefIntegral(function<double (double)> ChosenFunc)
{
    double st, en;
    int n = 1000;
    
    cout << "Введите границы отрезка: "; cin >> st >> en;

    double e = 0.0001;
    int k = 10;
    int i = 0;
    double diff;
    
    do
    {
        i++;
        diff = fabs(IntegralCalc(st, en, k * i, ChosenFunc) - IntegralCalc(st, en, k * (i + 1), ChosenFunc));
        
    } while (diff > e);

    return  IntegralCalc(st, en, k * (i + 1), ChosenFunc);
}
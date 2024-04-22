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
    
    cout
    << "|------------------------------------------------|\n"
    << "|   >>> Определенный интеграл на отрезке <<<     |\n"
    << "|------------------------------------------------|\n" ;
    
    do
    {
        cout << "| Введите границы отрезка: "; cin >> st >> en;
    } while (st >= en);

    double e = 0.0001;
    int k = 10;
    int i = 0;
    double diff;
    
    do
    {
        i++;
        diff = abs(IntegralCalc(st, en, k * i, ChosenFunc) - IntegralCalc(st, en, k * (i + 1), ChosenFunc));
    } while (diff > e);

    cout << "| Значение интеграла: " <<IntegralCalc(st, en, k * (i + 1), ChosenFunc);

    char ans;
    cout << "\n| Продолжить работу с текущей функцией (0/1)? ";

    do
    {
        ans = _getch();
        if (ans != '0' || ans != '1')
            cout
            << "\n|------------------------------------------------|\n"
            << "|            >>> Ошбика ввода <<<                |\n"
            << "|------------------------------------------------|\n" ;;
    }
    while (ans != '0' && ans != '1');
    
    if (ans == '1')
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
#include <windows.h>

#include "3-FuC-File-01-Header.h"

void FindRoot(double a, double b, double eps, function<double(double)> ChosenFunc)
{
    double mid = (b + a) / 2;
    int iter = 0;

    if (goodFunc == 1)
    {
        if (wasMade == 1)
            cout << "| Корень уравнения: " << root;
        else cout << "| Нет корней";
        return;
    }
    
    if (ChosenFunc(a) * ChosenFunc(b) > 0)
    {
        cout << "| ОШИБКА: Функция имеет одинаковые знаки на концах отрезков..";
        return;
    }
    
    while (abs(ChosenFunc(mid)) > eps && iter < 3000)
    {
        if (ChosenFunc(mid) > 0)
            b = mid;
        else
            a = mid;
        mid = (b + a) / 2;
        iter++;
    }

    if (iter >= 3000)
        cout << "| ОШИБКА: RunTimeError";
    else
        cout << "| Корень уравнения: " << mid;
}

void runFuncRootCalc(function<double(double)> ChosenFunc)
{
    double st, en;
    double eps = 0.000001;

    cout
    << "|------------------------------------------------|\n"
    << "|        >>> Поиск корня на отрезке <<<          |\n"
    << "|------------------------------------------------|\n" ;
    
    do
    {
        cout << "| Введите границы отрезка: "; cin >> st >> en;
    } while (st > en);

    FindRoot(st, en, eps, ChosenFunc);


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
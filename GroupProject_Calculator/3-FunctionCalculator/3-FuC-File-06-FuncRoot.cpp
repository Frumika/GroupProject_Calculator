#include "3-FuC-File-01-Header.h"

void FindRoot(double a, double b, double eps, function<double(double)> ChosenFunc)
{
    double mid = (b + a) / 2;
    int iter = 0;

    if (ChosenFunc(a) * ChosenFunc(b) > 0)
    {
        cout << "ОШИБКА: Функция имеет одинаковые знаки на концах отрезков.." << endl;
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
        cout << "ОШИБКА: RunTimeError\n";
    else
        cout << "Корень уравнения: " << mid << endl;
}

void runFuncRootCalc(function<double(double)> ChosenFunc)
{
    double st, en;
    double eps = 0.0001;

    do
    {
        cout << "Введите границы отрезка: "; cin >> st >> en;
    } while (st > en);

    FindRoot(st, en, eps, ChosenFunc);

    int ans;
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
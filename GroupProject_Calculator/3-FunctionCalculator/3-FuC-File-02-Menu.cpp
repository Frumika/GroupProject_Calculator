#include "3-FuC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"

double root = 0;
bool wasMade = false;
bool goodFunc = false;

void runFunctionCalculator()
{
    char select;
    bool cond;
    
    cout
        << "|------------------------------------------------|\n"
        << "|              >>> Выбор функции <<<             |\n"
        << "|------------------------------------------------|\n" 
        << "| 1. Полином степени N                           |\n" 
        << "| 2. Степенная функция                           |\n" 
        << "| 3. Показательная функция                       |\n" 
        << "| 4. Логарифмическая функция                     |\n" 
        << "| 5. Синусоида                                   |\n"
        << "| 6. Косинусоида                                 |\n"
        << "| 0. Выйти в главное меню                        |\n" 
        << "|------------------------------------------------|\n";

    do
    {
        select = _getch();
        
        cond = (
            select == '1' ||
            select == '2' ||
            select == '3' ||
            select == '4' ||
            select == '5' ||
            select == '6' ||
            select == '0');
    }
    while (cond == false);

    system("cls");
    
    switch (select)
    {
        case '1':
            {
                int n = 0;

                cout
                << "|------------------------------------------------|" << endl
                << "|        >>> Введите степень полинома <<<        |" << endl
                << "|------------------------------------------------|" << endl;
                
                cout << "| "; cin >> n;
                cout << "|------------------------------------------------|" << endl;

                n += 1;
            
                double *arr = new double [n];

                cout << "| a0";
                for (int i = 1; i < n; i++)
                {
                    if ((i + 1) <= n) cout << " + ";
                    cout << "a" << i << " * " << "x^" << i;
                }
                cout << endl;
                cout << "|------------------------------------------------|" << endl;

                double s = 0;
                
                do
                {
                    
                    cout << "| Введите члены полинома: ";
            
                    for (int i = 0; i < n; i++)
                    {
                        cin >> arr[i];
                        if (i != 0) s += arr[i];
                    }
                }
                while (s == 0);
                
                auto ChosenFunc = [&arr, &n](double x)
                {
                    return PolynomFunc(x, arr, n);
                };

                runSecondFuncMenu(ChosenFunc);
            }
            break;
        case '2':
            {
                double a,b,c;
                cout
                << "|------------------------------------------------|" << endl
                << "|           >>> Степенная функция <<<            |" << endl
                << "|------------------------------------------------|" << endl
                << "|                  a * x^b + c                   |" << endl
                << "|------------------------------------------------|" << endl;
                
                do
                {
                    cout << "| Введите значения a, b, c: "; cin >> a >> b >> c;
                }
                while (a == 0 || b == 0);

                
                auto ChosenFunc = [&a, &b, &c](double x)
                {
                    return DegreeFunc(x, a, b, c);
                };

                runSecondFuncMenu(ChosenFunc);
            }
            break;
        case '3':
            {
                double a,b,c,d;

                cout
                << "|------------------------------------------------|" << endl
                << "|          >>> Показательная функция <<<         |" << endl
                << "|------------------------------------------------|" << endl
                << "|                a * b^(c * x) + d               |" << endl
                << "|------------------------------------------------|" << endl;
                
                do
                {
                    cout << "| Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;
                }
                while (a == 0 || c == 0);
                
                auto ChosenFunc = [&a, &b, &c, &d](double x)
                {
                    return ExponentFunc(x, a, b, c, d);
                };
            
                runSecondFuncMenu(ChosenFunc);
            }
            break;
            case '4':
                {
                    double a,b,c;

                    cout
                    << "|------------------------------------------------|" << endl
                    << "|        >>> Логарифмическая функция  <<<        |" << endl
                    << "|------------------------------------------------|" << endl
                    << "|               a * log(b * x) + c               |" << endl
                    << "|------------------------------------------------|" << endl;
                    
                    do
                    {
                        cout << "| Введите значения a, b, c: "; cin >> a >> b >> c;
                    }
                    while (a == 0 || b <= 0);

                    auto ChosenFunc = [&a, &b, &c](double x)
                    {
                        return LogFunc(x, a, b, c);
                    };

                    system("cls");
                    runSecondFuncMenu(ChosenFunc);
                }
            break;
            case '5':
                {
                    double a,b,c,d;

                    cout
                    << "|------------------------------------------------|" << endl
                    << "|               >>> Синусоида <<<                |" << endl
                    << "|------------------------------------------------|" << endl
                    << "|             a * sin(b * x + c) + d             |" << endl
                    << "|------------------------------------------------|" << endl;
                    
                    cout << "| Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;

                    goodFunc = true;

                    if ((-d/a <= 1 && -d/a >= -1))                    
                        root = (asin(-d/a) - c) / b;
                    else wasMade = false;
                    
                    auto ChosenFunc = [&a, &b, &c, &d](double x)
                    {
                        return SinFunc(x, a, b, c, d);
                    };

                    runSecondFuncMenu(ChosenFunc);
                }
            break;
            case '6':
                {
                    double a,b,c,d;

                    cout
                    << "|------------------------------------------------|" << endl
                    << "|                >>> Косинусоида <<<             |" << endl
                    << "|------------------------------------------------|" << endl
                    << "|               a * cos(b * x + c) + d           |" << endl
                    << "|------------------------------------------------|" << endl;
                    
                    cout << "| Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;

                    goodFunc = true;
                    
                    if ((-d/a <= 1 && -d/a >= -1))                    
                        root = (acos(-d/a) - c) / b;
                    else wasMade = false;
                    
                    auto ChosenFunc = [&a, &b, &c, &d](double x)
                    {
                        return CosFunc(x, a, b, c, d);
                    };

                    runSecondFuncMenu(ChosenFunc);
                }
            break;
            default:
                runMainMenu();
        }
}

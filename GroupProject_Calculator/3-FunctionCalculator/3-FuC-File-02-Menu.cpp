#include "3-FuC-File-01-Header.h"

void runFunctionCalculator()
{
    char select;
    bool cond;
    
    cout
        << "+-------------------------------------------------+\n"
        << "|              >>> Выбор функции <<<              |\n"
        << "|-------------------------------------------------|\n" 
        << "| 1. Полином степени N                            |\n" 
        << "| 2. Степенная функция                            |\n" 
        << "| 3. Показательная функция                        |\n" 
        << "| 4. Логарифмическая функция                      |\n" 
        << "| 5. Синусоида                                    |\n"
        << "| 6. Косинусоида                                  |\n"
        << "| 0. Выйти в главное меню                         |\n" 
        << "+-------------------------------------------------+\n";

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

    switch (select)
    {
    case '1':
        {
            system("cls");
        }
        break;
    case '2':
        {
            system("cls");
            double a,b,c;
            
            cout << "Введите значения a, b, c: "; cin >> a >> b >> c;
            
            auto ChosenFunc = [&a, &b, &c, d = 0](double x)
            {
                return DegreeFunc(x, a, b, c, d);
            };

            system("cls");
            runSecondFuncMenu(ChosenFunc);
        }
        break;
    case '3':
        {
            system("cls");
            double a,b,c,d;
            
            cout << "Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;
            
            auto ChosenFunc = [&a, &b, &c, &d](double x)
            {
                return ExponentFunc(x, a, b, c, d);
            };
            
            system("cls");
            runSecondFuncMenu(ChosenFunc);
        }
        break;
    case '4':
        {
            system("cls");
            double a,b,c;
            
            cout << "Введите значения a, b, c: "; cin >> a >> b >> c;
            
            auto ChosenFunc = [&a, &b, &c, d = 0](double x)
            {
                return LogFunc(x, a, b, c, d);
            };

            system("cls");
            runSecondFuncMenu(ChosenFunc);
        }
        break;
    case '5':
        {
            system("cls");
            double a,b,c,d;
            
            cout << "Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;
            
            auto ChosenFunc = [&a, &b, &c, &d](double x)
            {
                return SinFunc(x, a, b, c, d);
            };
            
            system("cls");
            runSecondFuncMenu(ChosenFunc);
        }
        break;
    case '6':
        {
            system("cls");
            double a,b,c,d;
            
            cout << "Введите значения a, b, c, d: "; cin >> a >> b >> c >> d;
            
            auto ChosenFunc = [&a, &b, &c, &d](double x)
            {
                return CosFunc(x, a, b, c, d);
            };

            system("cls");
            runSecondFuncMenu(ChosenFunc);
        }
        break;
    default:
        cout << "Dab";
        break;
    }
    
}
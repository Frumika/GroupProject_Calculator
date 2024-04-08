#include <functional>

#include "3-FuC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"

void runSecondFuncMenu(function<double(double)> ChosenFunc)
{
    char select;
    bool cond;
    
    cout
    << "|-------------------------------------------------|\n"
    << "|              >>> Выбор действия <<<             |\n"
    << "|-------------------------------------------------|\n" 
    << "| 1. Вычисление определенного                     |\n"
       "|    интеграла на отрезке                         |\n" 
    << "| 2. Построить график функции                     |\n" 
    << "| 3. Поиск корня на отрезке                       |\n" 
    << "| 4. Поиск экстремумов на отрезке                 |\n" 
    << "| 0. Назад                                        |\n" 
    << "|-------------------------------------------------|\n";

    do
    {
        select = _getch();
        cond = (
            select == '1' ||
            select == '2' ||
            select == '3' ||
            select == '4' ||
            select == '0');
    }
    while (cond == false);

    system("cls");

    switch (select)
    {
        case '1':
            {
                runDefIntegral(ChosenFunc);
            }
        break;
        case '2':
            {
                DrawFunc(ChosenFunc);
            }
        break;
        case '3':
            {
                runFuncRootCalc(ChosenFunc);
            }
        break;
        case '4':
            {
                runExtremumCalc(ChosenFunc);
            }
        break;
        default:
            runFunctionCalculator();
    }
}

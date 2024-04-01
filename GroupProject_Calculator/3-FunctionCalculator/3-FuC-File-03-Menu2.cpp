#include <functional>

#include "3-FuC-File-01-Header.h"

void runSecondFuncMenu(function<double(double)> ChosenFunc)
{
    char select;
    bool cond;
    
    cout
    << "+-------------------------------------------------+\n"
    << "|              >>> Выбор действия <<<             |\n"
    << "|-------------------------------------------------|\n" 
    << "| 1. Вычисление определенного                     |\n"
       "|    интеграла на отрезке                         |\n" 
    << "| 2. Построить график функции                     |\n" 
    << "| 3. Поиск корня на отрезке                       |\n" 
    << "| 4. Поиск экстремумов на отрезке                 |\n" 
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
            select == '0');
    }
    while (cond == false);

    switch (select)
    {
    case '1':
        {
            system("cls");
            cout << runDefIntegral(ChosenFunc);
        }
        break;
    case '2':
        {
            system("cls");
        }
        break;
    case '3':
        {
            system("cls");
        }
        break;
    case '4':
        {
            system("cls");
        }
        break;
    default:
        break;
    }
    
}
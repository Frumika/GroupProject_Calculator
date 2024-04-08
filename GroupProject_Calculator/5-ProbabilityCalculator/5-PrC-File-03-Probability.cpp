#include "5-PrC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

/* Калькулятор вероятности */
void runProbability()
{
    int precision;
    double n, m;

    do
    {
        cout
            << "|-----------------------------------------|" << endl
            << "|             >>> Справка <<<             |" << endl
            << "| *n и m должны быть больше 0             |" << endl
            << "| *после точки может быть от 0 до 10 цифр |" << endl
            << "|-----------------------------------------|" << endl << endl
            << "Введите n и m: ";
         cin >> n >> m;
        //Проверки на дурака
        if(n <= 0)
        {
            cout << "n не может быть равен или меньше 0!";
            _getch();
        }
        else if(m <= 0)
        {
            cout << "m не может быть равен или меньше 0!";
            _getch();
        }
        system("cls");
    }
    while (n <= 0 || m <= 0);
    //Узнаём у пользователя сколько цифр после точки выводить
    do
    {
        cout << "Округлить до: ", cin >> precision;
        if(precision < 0)
        {
            cout << "Цифр после точки не может быть меньше 0!";
            _getch();
        }
        else if(precision > 10)
        {
            cout << "Цифр после точки не может быть больше 10!";
            _getch();
        }
        system("cls");
    }
    while (precision < 0 || precision > 10);
    cout << setprecision(precision+1) << "n/m = " << n/m;

    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}
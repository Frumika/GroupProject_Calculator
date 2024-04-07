#include "4-CoC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

/* Сочетание с повторениями */
void runCombinationWithRep()
{
    int n, m;
    
    do
    {
        cout
            << "|-----------------------------------------------------|" << endl
            << "|                   >>> Справка <<<                   |" << endl
            << "| *элементов может быть от 1 до 100                   |" << endl
            << "| *сочетаний может быть от 1 до 100                   |" << endl
            << "| *элементов должно быть больше или равно сочетаниям  |" << endl
            << "|-----------------------------------------------------|" << endl << endl
            << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        //Проверки на дурака
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 2!";
            _getch();
        }
        else if(n > 100)
        {
            cout << "Элементов не может быть больше 100!";
            _getch();
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
        }
        system("cls");
    }
    while (n < 1 || n > 100 || m < 1 || n < m);
    cout << "F = " << setprecision(numeric_limits<double>::max_digits10) << factorial(m+n-1)/(factorial(m-1)*factorial(n));
    
    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}

/* Сочетание без повторений */
void runCombinationWithoutRep()
{
    int n, m;
    
    do
    {
        cout
            << "|-----------------------------------------------------|" << endl
            << "|                   >>> Справка <<<                   |" << endl
            << "| *элементов может быть от 1 до 100                   |" << endl
            << "| *сочетаний может быть от 1 до 100                   |" << endl
            << "| *элементов должно быть больше или равно сочетаниям  |" << endl
            << "|-----------------------------------------------------|" << endl << endl
            << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        //Проверки на дурака
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 1!";
            _getch();
        }
        else if(n > 100)
        {
            cout << "Элементов не может быть больше 100!";
            _getch();
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
        }
        system("cls");
    }
    while (n < 1 || n > 100 || m < 1 || n < m);
    cout << "F = " << setprecision(numeric_limits<double>::max_digits10) << factorial(n)/(factorial(m)*factorial(n-m));
    
    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}
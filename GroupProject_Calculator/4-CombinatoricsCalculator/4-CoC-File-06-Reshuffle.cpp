#include "4-CoC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

/* Перестановка */
void runReshuffle()
{
    int n;
    long double num;
    
    do
    {
        cout
            << "|-----------------------------------------------------|" << endl
            << "|                   >>> Справка <<<                   |" << endl
            << "| *элементов может быть от 1 до 100                   |" << endl
            << "|-----------------------------------------------------|" << endl << endl
            << "Введите количество элементов: ", cin >> n;
        //Проверка на дурака
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
        system("cls");
    }
    while (n < 1 || n > 100);
    num = factorial(n);
    cout << "F! = " << fixed << setprecision(0) << num;    //Точность хромает при очень большом числе
    
    _getch();   //Не даёт сразу выйти в меню
    system("cls");
}
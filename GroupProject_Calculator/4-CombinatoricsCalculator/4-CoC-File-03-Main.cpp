#include "4-CoC-File-01-Header.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

double factorial(int n)
{
    double k = 1;
    for(; n > 0; k *= n, n--);
    return k;
}

double pow(int n, int m)
{
    double k = 1;
    for(; m > 0; k *= n, m--);
    return n;
}

void placementWithRep()
{
    int n, m;
    
    do
    {
        cout << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
            system("cls");
        }
    }
    while (n < 1 || m < 1 || n < m);
    cout << "F = " << fixed << setprecision(0) << pow(n, m);
    _getch();
}

void placementWithoutRep()
{
    int n, m;
    
    do
    {
        cout << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
            system("cls");
        }
    }
    while (n < 1 || m < 1 || n < m);
    cout << "F = " << fixed << setprecision(0) << factorial(n)/factorial(n-m);
    _getch();
}

void combinationWithRep()
{
    int n, m;
    
    do
    {
        cout << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
            system("cls");
        }
    }
    while (n < 1 || m < 1 || n < m);
    cout << "F = " << fixed << setprecision(0) << factorial(m+n-1)/(factorial(m-1)*factorial(n));
    _getch();
}

void combinationWithoutRep()
{
    int n, m;
    
    do
    {
        cout << "Введите количество элементов и сочетаний: ", cin >> n >> m;
        if(n < 1)
        {
            cout << "Элементов не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(m < 1)
        {
            cout << "Сочетаний не может быть меньше 1!";
            _getch();
            system("cls");
        }
        else if(n < m)
        {
            cout << "Элементов не может быть меньше сочетаний!";
            _getch();
            system("cls");
        }
    }
    while (n < 1 || m < 1 || n < m);
    cout << "F = " << fixed << setprecision(0) << factorial(n)/(factorial(m)*factorial(n-m));
    _getch();
}

void reshuffle()
{
    int n;
    
    do
    {
        cout << "Введите число перестановок: ", cin >> n;
        if(n < 1)
        {
            cout << "Перестановок не может быть меньше 1!";
            _getch();
            system("cls");
        }
    }
    while (n < 1);
    cout << "F! = " << fixed << setprecision(0) << factorial(n);
    _getch();
}
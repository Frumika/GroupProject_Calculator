#include <conio.h>
#include <iostream>
#include "1-MaC-File-01-Header.h"

using namespace std;

/*
 * displayMatrixMenu - Фунция вывода меню матричного калькулятора
 * 
 * C помощью функции _getch() в переменную button записывается занчение, считываемое с клавиатуры
 * В цикле do-while с помощью переменной condition проверяется кооректность ввода
 * С помощью switch-case выбирается необходимая функция
 */
void displayMatrixMenu()
{
    char button; // в эту переменную записывается занчение, считываемое с клавиатуры
    bool condition; // условие корректности считываемого занчения

    cout
        << "|------------------------------------------------|" << endl
        << "|          >>> Матричный калькулятор <<<         |" << endl
        << "|------------------------------------------------|" << endl
        << "| 1. Сложение и вычитание матриц                 |" << endl
        << "| 2. Умножение матриц                            |" << endl
        << "| 3. Умножение матрицы на число                  |" << endl
        << "| 4. Сложение (вычитание) числа с матрицей       |" << endl
        << "| 5. Транспонирование матрицы                    |" << endl
        << "| 6. Обратная матрица                            |" << endl
        << "| 0. Вернуться в главное меню                    |" << endl
        << "|------------------------------------------------|" << endl;

    do
    {
        button = _getch(); // считываем занчение с клавиатуры

        condition = (button == '1' ||
            button == '2' ||
            button == '3' ||
            button == '4' ||
            button == '5' ||
            button == '6' ||
            button == '7' ||
            button == '0');// проверяем корректность вводимого значения
    }
    while (condition == false);


    switch (button) // в зависимости от введенного знчения вызываем функцию 
    {
    case '1':
        {
            system("cls");
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
    case '5':
        {
            system("cls");
        }
        break;
    case '6':
        {
            system("cls");
        }
        break;

    default:
        {
            system("cls");
            runMainMenu();
        }
    }
}

void runMatrixCalculator()
{
    displayMatrixMenu();
}

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
        << "| 1. Сложение матриц                             |" << endl
        << "| 2. Вычитание матриц                            |" << endl
        << "| 3. Умножение матриц                            |" << endl
        << "| 4. Умножение матрицы на число                  |" << endl
        << "| 5. Сложение (вычитание) числа с матрицей       |" << endl
        << "| 6. Транспонирование матрицы                    |" << endl
        << "| 7. Определитель матрицы                        |" << endl
        << "| 8. Обратная матрица                            |" << endl
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
            button == '8' ||
            button == '0'); // проверяем корректность вводимого значения
    }
    while (condition == false);


    switch (button) // в зависимости от введенного знчения вызываем функцию 
    {
    case '1':
        {
            system("cls");
            runTest();
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
    case '7':
        {
            system("cls");
        }
        break;
    case '8':
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

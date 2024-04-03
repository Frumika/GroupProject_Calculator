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

    system("cls");

    switch (button) // в зависимости от введенного знчения вызываем функцию 
    {
    case '1':
        {
            runSumMatrix(0);
        }
        break;
    case '2':
        {
            runSubMatrix();
        }
        break;
    case '3':
        {
            runMultiplicationMatrix(0);
        }
        break;
    case '4':
        {
            runMultiplicationMatrix(1);
        }
        break;
    case '5':
        {
            runSumMatrix(1);
        }
        break;
    case '6':
        {
            runTranspositionMatrix();
        }
        break;
    case '7':
        {
            runDeterminantMatrix();
        }
        break;
    case '8':
        {
            runInverseMatrix();
        }
        break;

    default:
        {
            runMainMenu();
        }
    }
}

void runMatrixCalculator()
{
    displayMatrixMenu();
}

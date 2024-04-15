﻿#include <conio.h>
#include <iostream>
#include "1-MaC-File-01-Header.h"

using namespace std;


/*
 * Функция runMatrixToMatrix отвечает за:
 *  1. Ввод двух матриц.
 *  2. Нахождение произведния матриц.
 *  3. Вывод результата на экран.
 *  4. Очистку данных.
 * После того как функция завершит свою работу будет вызвана функция displayMatrixMenu.
 */
void runMatrixToMatrix()
{
    Matrix* matrixA;
    Matrix* matrixB;
    int n1, m1;
    int n2, m2;

    cout
        << "|------------------------------------------------|" << endl
        << "|            >>> Умножение матриц <<<            |" << endl
        << "|------------------------------------------------|" << endl;

    do
    {
        cout
            << "|------------------------------------------------|" << endl
            << "|          Введите размеры первой матрицы        |" << endl
            << "|------------------------------------------------|" << endl;
        do
        {
            cout << "| Введите кол-во строк матриц: ";
            cin >> n1;
            if (n1 <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
        }
        while (n1 <= 0);

        cout << "|------------------------------------------------|" << endl;

        do
        {
            cout << "| Введите кол-во столбцов матриц: ";
            cin >> m1;
            if (m1 <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
        }
        while (m1 <= 0);


        cout
            << "|------------------------------------------------|" << endl
            << "|          Введите размеры второй матрицы        |" << endl
            << "|------------------------------------------------|" << endl;
        do
        {
            cout << "| Введите кол-во строк матриц: ";
            cin >> n2;
            if (n2 <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
        }
        while (n2 <= 0);

        cout << "|------------------------------------------------|" << endl;

        do
        {
            cout << "| Введите кол-во столбцов матриц: ";
            cin >> m2;
            if (m2 <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
        }
        while (m2 <= 0);

        if (n1 != m2) cout << "| Ошибка: Неправильные размеры матриц" << endl;

        cout << "|------------------------------------------------|" << endl;
    }
    while (n1 != m2);


    cout
        << "|            Введите первую матрицу              |" << endl
        << "|------------------------------------------------|" << endl;


    matrixA = enterMatrix(n1, m1);


    cout
        << "|------------------------------------------------|" << endl
        << "|            Введите вторую матрицу              |" << endl
        << "|------------------------------------------------|" << endl;

    matrixB = enterMatrix(n2, m2);

    matrixA = multiplicationMatrix(matrixA, matrixB);

    cout
        << "|------------------------------------------------|" << endl
        << "|                   Ответ                        |" << endl
        << "|------------------------------------------------|" << endl;

    printMatrix(matrixA);
    clearMatrix(matrixA);

    cout
        << "|------------------------------------------------|" << endl
        << "|      Нажмите любую клавишу чтобы продолжить    |" << endl
        << "|------------------------------------------------|" << endl;

    _getch();
    system("cls");
    displayMatrixMenu();
}

/*
 * Функция runMatrixToNumber отвечает за:
 *  1. Ввод числа и матрицы.
 *  2. Нахождение произведния числа и матрицы.
 *  3. Вывод результата на экран.
 *  4. Очистку данных.
 * После того как функция завершит свою работу будет вызвана функция displayMatrixMenu.
 */
void runMatrixToNumber()
{
    Matrix* matrixA;
    int n, m;
    double* number = new double;

    cout
        << "|------------------------------------------------|" << endl
        << "|       >>> Умножение матрицы на число <<<       |" << endl
        << "|------------------------------------------------|" << endl;

    cout << "| Введите число: ";
    cin >> *number;
    cout << "|------------------------------------------------|" << endl;

    do
    {
        cout << "| Введите кол-во строк матрицы: ";
        cin >> n;
        if (n <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
    }
    while (n <= 0);

    cout << "|------------------------------------------------|" << endl;

    do
    {
        cout << "| Введите кол-во столбцов матрицы: ";
        cin >> m;
        if (m <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
    }
    while (m <= 0);

    cout
        << "|------------------------------------------------|" << endl
        << "|                Введите матрицу                 |" << endl
        << "|------------------------------------------------|" << endl;


    matrixA = enterMatrix(n, m);
    multiplicationMatrix(matrixA, number);

    cout
        << "|------------------------------------------------|" << endl
        << "|                   Ответ                        |" << endl
        << "|------------------------------------------------|" << endl;

    printMatrix(matrixA);
    clearMatrix(matrixA);

    cout
        << "|------------------------------------------------|" << endl
        << "|      Нажмите любую клавишу чтобы продолжить    |" << endl
        << "|------------------------------------------------|" << endl;

    _getch();
    system("cls");
    displayMatrixMenu();
}


/*
 * Функция runMultiplicationMatrix отвечает за запуск необходимой функции умножения в зависимости от переданного значения key.
 * Если key == 0 то запускается функция умножения двух матриц runMatrixToMatrix.
 * Иначе - функция умножения числа с матрицей runMatrixToNumber.
 */
void runMultiplicationMatrix(bool key)
{
    if (key == 0) runMatrixToMatrix();
    else runMatrixToNumber();
}
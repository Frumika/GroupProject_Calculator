﻿#include <conio.h>
#include <iostream>
#include "1-MaC-File-01-Header.h"

using namespace std;


/*
 * Функция runSubMatrix отвечает за:
 *  1. Ввод двух матриц.
 *  2. Нахождение нахождение разности этих матриц.
 *  3. Вывод результата на экран.
 *  4. Очистку данных.
 * После того как функция завершит свою работу будет вызвана функция displayMatrixMenu.
 */
void runSubMatrix()
{
    Matrix* matrixA;
    Matrix* matrixB;
    int n, m;

    cout
        << "|------------------------------------------------|" << endl
        << "|            >>> Вычитание матриц <<<            |" << endl
        << "|------------------------------------------------|" << endl;

    do
    {
        cout << "| Введите кол-во строк матриц: ";
        cin >> n;
        if (n <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
    }
    while (n <= 0);

    cout << "|------------------------------------------------|" << endl;

    do
    {
        cout << "| Введите кол-во столбцов матриц: ";
        cin >> m;
        if (m <= 0) cout << "| Ошибка: Введите целое положительное число" << endl;
    }
    while (m <= 0);

    cout
        << "|------------------------------------------------|" << endl
        << "|            Введите первую матрицу              |" << endl
        << "|------------------------------------------------|" << endl;


    matrixA = enterMatrix(n, m);


    cout
        << "|------------------------------------------------|" << endl
        << "|            Введите вторую матрицу              |" << endl
        << "|------------------------------------------------|" << endl;

    matrixB = enterMatrix(n, m);

    subtractMatrix(matrixA, matrixB);

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

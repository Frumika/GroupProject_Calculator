#include "1-MaC-File-01-Header.h"
#include "iostream"

using namespace std;

/*
 * enterMatrix - Функция создающая матрицу размером NxM и заполняющая её.
 * Функция принимает 2 аргумента - n и m, где n - число строк, а m - число столбцов.
 * Функция возвращает указатель на новую матрицу.
 */
Matrix* enterMatrix(int n, int m)
{
    Matrix* matrixA = new Matrix; // Объявляем новую матрицу

    matrixA->matrix = new double*[n]; // Создаем динамический массив указателей на строки матрицы
    matrixA->n = new int{n}; // Количество строк новой матрицы
    matrixA->m = new int{m}; // Количество столбцов новой матрицы

    for (int i = 0; i < n; i++)
    {
        matrixA->matrix[i] = new double[m]; // Создаём i-тую строку матрицы состоящую из m столбцов
        cout << "| Введите " << i + 1 << "-ю строку матрицы: ";
        for (int j = 0; j < m; j++) cin >> matrixA->matrix[i][j]; // Вводим m занчений с клавиатуры
    }

    return matrixA; // Возвращаем указатель на созданную матрицу
}

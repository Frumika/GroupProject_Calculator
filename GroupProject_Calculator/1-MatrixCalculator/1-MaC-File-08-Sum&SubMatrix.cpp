#include "1-MaC-File-01-Header.h"

/*
 * Функция sumMatrix принимает на вход два указателя на тип Matrix.
 * В результате выполения функции происходит сложение переданных матриц.
 * Результат сложения записывается в первую переданную матрицу (matrixA), вторая переданная матрица (matrixB) уничтожается
 */
Matrix* sumMatrix(Matrix* matrixA, Matrix* matrixB)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] + matrixB->matrix[i][j];
        }
    }
    clearMatrix(matrixB);
    return matrixA;
}

/*
 * Функция subtractMatrix принимает на вход два указателя на тип Matrix.
 * В результате выполения функции из первой переданной матрицы (matrixA) вычитается вторая переданная матрица (matrixB)
 * Результат вычитания записывается в первую переданную матрицу (matrixA), вторая переданная матрица (matrixB) уничтожается
 */
Matrix* subtractMatrix(Matrix* matrixA, Matrix* matrixB)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] - matrixB->matrix[i][j];
        }
    }
    clearMatrix(matrixB);
    return matrixA;
}

/*
 * Функция sumMatrix принимает на вход два указателя первый указывет на тип Matrix второй - на тип double.
 * В результате выполнения функции происходит сложение или вычитание переменной number с каждым числом записанным в матрице.
 * Результат выполнения функции записывается в переданную матрицу (matrixA)
 */
Matrix* sumMatrix(Matrix* matrixA, double* number)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] + *number;
        }
    }
    return matrixA;
}

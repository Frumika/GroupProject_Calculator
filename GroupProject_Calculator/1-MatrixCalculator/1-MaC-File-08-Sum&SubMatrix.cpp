#include "1-MaC-File-01-Header.h"


/*
 * Функция sumMatrix в качестве аргуметов принимает 2 укзателя на матрицы (на matrixA и на matrixB).
 * В ходе выполнения функции в первую входящую матрицу (matrixA) записывается результат сложения матриц.
 * Вторая переданная матрица (matrixB) уничтожается.
 * Первая переданная матрица (matrixA) видоизменяется и не удаляется.
 * Функция не возвращает занчений.
 */
void sumMatrix(Matrix* matrixA, Matrix* matrixB)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] + matrixB->matrix[i][j];
        }
    }
    clearMatrix(matrixB);
}


/*
 * Функция sumMatrix в качестве аргуметов принимает 2 укзателя - на матрицу и на число.
 * В ходе выполнения функции в первую входящую матрицу (matrixA) записывается результат сложения матрицы и числа.
 * Переданное число уничтожается.
 * Переданная матрица (matrixA) видоизменяется и не удаляется.
 * Функция не возвращает занчений.
 */
void sumMatrix(Matrix* matrixA, double* number)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] + *number;
        }
    }
    delete number;
}


/*
 * Функция subtractMatrix в качестве аргуметов принимает 2 укзателя на матрицы (на matrixA и на matrixB).
 * В ходе выполнения функции в первую входящую матрицу (matrixA) записывается результат вычитания матриц.
 * Вторая переданная матрица (matrixB) уничтожается.
 * Первая переданная матрица (matrixA) видоизменяется и не удаляется.
 * Функция не возвращает занчений.
 */
void subtractMatrix(Matrix* matrixA, Matrix* matrixB)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] - matrixB->matrix[i][j];
        }
    }
    clearMatrix(matrixB);
}

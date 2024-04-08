#include "1-MaC-File-01-Header.h"


/*
 * Функция findDeterminant принимает указатель на матрицу.
 * В результате выполнения функции вычисляется определитель входящей матрицы (matrixA).
 * Входящая матрица не удаляется и не видоизменяется.
 * Функция возвращает указатель на определитель матрицы.
 */
double* findDeterminant(Matrix* matrixA)
{
    int* swap = new int{0};
    double* determinant = new double{1};
    Matrix* matrixB = new Matrix;

    matrixB = createStepMatrix(matrixA, swap);

    for (int i = 0; i < *matrixB->n; i++)
    {
        *determinant *= matrixB->matrix[i][i];
    }
    clearMatrix(matrixB);

    if (*determinant == -0) *determinant = 0;
    if (*determinant != 0 && *swap % 2 != 0) *determinant = -*determinant;

    return determinant;
}

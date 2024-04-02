#include "1-MaC-File-01-Header.h"


/*
 * Функция multiplicationMatrixString принимает указатель на матрицу и номера 2-х соседних
 * строк этой матрицы.
 * Применяя метод Гаусса функция меняет эти 2-е строки прямо во входящей матирце.
 * Таким образом функция видоизменяет входящую матрицу.
 */
void multiplicationMatrixString(Matrix* matrixA, int i, int j)
{
    double multiplier = -1 * (matrixA->matrix[j][i] / matrixA->matrix[i][i]);

    for (int k = i; k < *matrixA->m; k++)
    {
        matrixA->matrix[j][k] = matrixA->matrix[i][k] * multiplier + matrixA->matrix[j][k];
    }
}


/*
 * Функция createStepMatrix принимает указатель типа Matrix на матрицу и на основе входящей матрицы
 * создает новую матрицу, на которую функция возвращает указатель.
 * При этом старая (входящая) матрица не удаляется
 */
Matrix* createStepMatrix(Matrix* matrixA)
{
    Matrix* matrixB = new Matrix;
    matrixB = copyMatrix(matrixA);

    for (int i = 0; i < *matrixB->n - 1; i++)
    {
        for (int j = i + 1; j < *matrixB->n; j++)
        {
            multiplicationMatrixString(matrixB, i, j);
        }
    }
    return matrixB;
}

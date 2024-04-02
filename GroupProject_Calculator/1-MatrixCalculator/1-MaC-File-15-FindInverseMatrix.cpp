#include "1-MaC-File-01-Header.h"


/* Функция findInverseMatrix принимает указатель на тип Matrix.
 * В ходе выполнения функции создается новая матрица (matrixB) которая является обратной входящей матрице (matrixA).
 * Функция возвращает указатель на новую матрицу (matrixB).
 * Старая матрица (matrixA) удаляется.
 */
Matrix* findInverseMatrix(Matrix* matrixA)
{
    Matrix* matrixB = new Matrix;
    double multiplier = 1 / findDeterminant(matrixA);

    matrixB->matrix = new double*[*matrixA->n];
    matrixB->n = new int{*matrixA->n};
    matrixB->m = new int{*matrixA->m};

    for (int i = 0; i < *matrixA->n; i++)
    {
        matrixB->matrix[i] = new double[*matrixA->m];

        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixB->matrix[i][j] = findAlgebraicComplement(matrixA, &i, &j);
        }
    }

    clearMatrix(matrixA);

    matrixB = transpositionMatrix(matrixB);

    matrixB = multiplicationMatrix(matrixB, &multiplier);

    return matrixB;
}

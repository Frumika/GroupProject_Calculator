#include "1-MaC-File-01-Header.h"


/*
 * Функция swapString принимает 3 указателя - на матрицу (matrixA) и на номера строк этой матрицы (i,j).
 * В результате выполнения функции строки i и j меняются местами.
 * Входящая матрица (matrixA) видоизменяется.
 * Функция не возвращает занчений.
 */
void swapString(Matrix* matrixA, int* i, int* j)
{
    double* buffer = new double;

    for (int k = 0; k < *matrixA->m; k++)
    {
        *buffer = matrixA->matrix[*i][k];
        matrixA->matrix[*i][k] = matrixA->matrix[*j][k];
        matrixA->matrix[*j][k] = *buffer;
    }
    delete buffer;
}


/*
 * Функция multiplicationMatrixString принимает указатель на матрицу и 2 на номера двух соседних строк этой матрицы.
 * В результате выполнения функции все значения в столбце ниже элемента с индексом [i][i] ставновятся равными нулю.
 * Входящая матрица видоизменяется, но не удаляется.
 * Функция не возвращает занчений.
 */
void multiplicationMatrixString(Matrix* matrixA, int* i, int* j, int* swap)
{
    double* multiplier = new double;

    if (matrixA->matrix[*i][*i] == 0)
    {
        if (matrixA->matrix[*j][*i] != 0)
        {
            swapString(matrixA, i, j);
            *swap = *swap + 1;
        }

        else
        {
            for (int new_j = *j + 1; new_j < *matrixA->m; new_j++)
            {
                if (matrixA->matrix[new_j][*i] != 0)
                {
                    swapString(matrixA, i, &new_j);
                    *swap = *swap + 1;
                    break;
                }
            }
        }
    }


    if (matrixA->matrix[*i][*i] != 0)
    {
        *multiplier = -1 * (matrixA->matrix[*j][*i] / matrixA->matrix[*i][*i]);

        for (int k = *i; k < *matrixA->m; k++)
        {
            matrixA->matrix[*j][k] = matrixA->matrix[*i][k] * *multiplier + matrixA->matrix[*j][k];
        }
    }

    delete multiplier;
}


/*
 * Функция createStepMatrix принимает указатель на матрицу (matrixA).
 * На основе переданной матрицы создается новая матрица (matrixB).
 * В результате выполнения функции создается ступенчатая матрица (matrixB) в соответствии с методом Гаусса.
 * Входящая матрица (matrixA) не удаляется.
 * Функция возвращает указатель на новую матрицу (matrixB)
 */
Matrix* createStepMatrix(Matrix* matrixA, int* swap)
{
    Matrix* matrixB = new Matrix;

    matrixB = copyMatrix(matrixA);

    for (int i = 0; i < *matrixB->n - 1; i++)
    {
        for (int j = i + 1; j < *matrixB->n; j++)
        {
            multiplicationMatrixString(matrixB, &i, &j, swap);
        }
    }
    return matrixB;
}

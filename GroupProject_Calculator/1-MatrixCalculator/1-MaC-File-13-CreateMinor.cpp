#include <iostream>
#include "1-MaC-File-01-Header.h"

/*
 * Функция createMinor принимает 3 указателя - на матрицу, на номер строки и на номер столбца.
 * В ходе выполнения функции создается новая матрица (matrixB) которая является минором входящей матрицы (matrixA).
 * Функция возвращает указатель на новую матрицу.
 * Старая матрица (matrixA) не видоизменяется и не уничтожается.
 */
Matrix* createMinor(Matrix* matrixA, int* iA, int* jA)
{
    Matrix* matrixB = new Matrix;

    matrixB->matrix = new double*[*matrixA->n - 1];
    matrixB->n = new int{*matrixA->n - 1};
    matrixB->m = new int{*matrixA->m - 1};
    

    for (int i = 0, iB = 0; i < *matrixA->n; i++)
    {
        if (i != *iA)
        {
            matrixB->matrix[iB] = new double [*matrixB->m];
            
            for (int j = 0, jB = 0; j < *matrixA->m; j++)
            {
                if (j != *jA)
                {
                    matrixB->matrix[iB][jB] = matrixA->matrix[i][j];
                    jB++;
                }
            }
            iB++;
        }
    }
    
    return matrixB;
}

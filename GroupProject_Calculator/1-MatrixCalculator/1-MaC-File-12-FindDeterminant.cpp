#include "1-MaC-File-01-Header.h"

/*
 * Функция findDeterminant принимает указатель на тип Matrix.
 * В ходе выполнения функции создается новая матрица (matrixB) которая является входящей матрицей (matrixA)
 * приведенной к ступенчатому виду.
 * Входящая матрица (matrixA) не удаляется и не видоизменяется.
 * В результате выполнения функции вычисляется определитель входящей матрицы и удаляется ступенчатая матрица (matrixB)
 * Функция возвращает значение типа double являющееся определителем матрицы.
 */
double findDeterminant(Matrix* matrixA)
{
    double determinant = 1;
    Matrix* matrixB = new Matrix;

    matrixB = createStepMatrix(matrixA);

    for (int i = 0; i < *matrixB->n; i++)
    {
        determinant *= matrixB->matrix[i][i];
    }
    clearMatrix(matrixB);

    return determinant;
}

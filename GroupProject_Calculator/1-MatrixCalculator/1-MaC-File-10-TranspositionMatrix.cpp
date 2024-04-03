#include "1-MaC-File-01-Header.h"


/*
 * Функция transpositionMatrix в качестве аргуммента принимает матрицу.
 * В результате выполнения функции создается новая матрица (matrixB) которая является транспонированной входящей матрицей (matrixA).
 * Входящая матрица (matrixA) удаляется.
 * Функция возвращает указатель на новую матрицу.
 */
Matrix* transpositionMatrix(Matrix* matrixA)
{
    Matrix* matrixB = new Matrix; // Объявляем новую матрицу

    matrixB->matrix = new double*[*matrixA->m]; // Создаем динамический массив указателей на строки матрицы
    matrixB->n = new int{*matrixA->m}; // Количество строк новой матрицы
    matrixB->m = new int{*matrixA->n}; // Количество столбцов новой матрицы

    for (int i = 0; i < *matrixB->n; i++)
    {
        matrixB->matrix[i] = new double[*matrixB->m];
        for (int j = 0; j < *matrixB->m; j++)
        {
            matrixB->matrix[i][j] = matrixA->matrix[j][i];
        }
    }
    clearMatrix(matrixA);

    return matrixB;
}

#include "1-MaC-File-01-Header.h"


/*
 * Функция sumMatrixString в качестве аргуметов принимает 2 указателя на матрицы, и 2 указателя - на номер строки и на номер столбца.
 * В первой матрице (matrixA) рассматривается умножаемая строка.
 * Во второй матрице (matrixB) рассматривается умножаемый столбец.
 * Значения i и j являются "координатами" записи полученного числа в новой матрице.
 * Функция возвращает значение типа double
 */
double sumMatrixString(Matrix* matrixA, Matrix* matrixB, int* i, int* j)
{
    double sum = 0;
    int iA = 0 + *i, jA = 0;
    int iB = 0, jB = 0 + *j;

    for (int k = 0; k < *matrixB->n; k++)
    {
        sum += matrixA->matrix[iA][jA] * matrixB->matrix[iB][jB];
        jA++;
        iB++;
    }
    return sum;
}


/*
 * Функция multiplicationMatrix в качестве аргументов принимает 2 указателя на матрицы (на matrixA и на matrixB).
 * В результате выполнения функции создается новая матрица (matrixC) содержащая в себе результат умножения
 * первой входящей матрицы (matrixA) на вторую входящую матрицу (matrixB).
 * Обе входящих матрицы удаляются.
 * Функция возвращает указатель на новую созданную матрицу.
 */
Matrix* multiplicationMatrix(Matrix* matrixA, Matrix* matrixB)
{
    Matrix* matrixC = new Matrix; // Объявляем новую матрицу

    matrixC->matrix = new double*[*matrixA->n]; // Создаем динамический массив указателей на строки матрицы
    matrixC->n = new int{*matrixA->n}; // Количество строк новой матрицы
    matrixC->m = new int{*matrixB->m}; // Количество столбцов новой матрицы

    for (int i = 0; i < *matrixC->n; i++)
    {
        matrixC->matrix[i] = new double[*matrixC->m];
        for (int j = 0; j < *matrixC->m; j++)
        {
            matrixC->matrix[i][j] = sumMatrixString(matrixA, matrixB, &i, &j);
        }
    }
    clearMatrix(matrixA);
    clearMatrix(matrixB);

    return matrixC;
}


/*
 * Фунцкция multiplicationMatrix в качестве аргументов принимает 2 указателя - на матрицу и на число.
 * В ходе выполнения функции значения входящей матрицы умножаются на входящее число.
 * В результате выполнения функции видоизменяется входящая матрица таким образом, что она содержит результат умножения.
 * Входящее число удаляется.
 * Функция не возвращает значения.
 */
void multiplicationMatrix(Matrix* matrixA, double* number)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++)
        {
            matrixA->matrix[i][j] = matrixA->matrix[i][j] * *number;
        }
    }
    delete number;
}

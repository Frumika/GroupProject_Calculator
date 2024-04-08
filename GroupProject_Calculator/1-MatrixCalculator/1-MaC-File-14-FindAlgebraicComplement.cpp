#include "1-MaC-File-01-Header.h"


/*
 * Функция findAlgebraicComplement принимает 3 указателя - на матрицу, на номер строки и на номер столбца.
 * В результате работы функции находится алгебрагическое дополнение входящей матрицы (matrixA) для "координат" iA и jA
 * Функция возвращает значение типа double.
 * Входящая матрица (matrixA) не видоизменяется и не уничтожается.
 */
double findAlgebraicComplement(Matrix* matrixA, int* iA, int* jA)
{
    Matrix* matrixB = new Matrix;
    double* determinant;

    matrixB = createMinor(matrixA, iA, jA);
    determinant = findDeterminant(matrixB);
    clearMatrix(matrixB);

    return (*iA + *jA) % 2 == 0 ? *determinant : -*determinant;
}

#include <iostream>
#include "1-MaC-File-01-Header.h"

// printMatrix - Функция для вывода матрицы на экран.
void printMatrix(Matrix* matrixA)
{
    for (int i = 0; i < *matrixA->n; i++)
    {
        for (int j = 0; j < *matrixA->m; j++) std::cout << matrixA->matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

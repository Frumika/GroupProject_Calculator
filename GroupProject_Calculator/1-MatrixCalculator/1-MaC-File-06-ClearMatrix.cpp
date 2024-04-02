#include "1-MaC-File-01-Header.h"

// clearMatrix - Функция для очитски памяти
void clearMatrix(Matrix* matrixA)
{
    for(int i = 0; i < *matrixA->n; i++) delete [] matrixA->matrix[i];
    delete [] matrixA->matrix;
    delete matrixA->n;
    delete matrixA->m;
    delete matrixA;
}
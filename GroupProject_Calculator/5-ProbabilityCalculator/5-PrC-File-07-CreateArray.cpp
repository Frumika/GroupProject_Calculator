#include "5-PrC-File-01-Header.h"

/* Создание массива */
double** createArray(int arraySize)
{
    double **x = new double*[2];
    x[0] = new double[arraySize];
    x[1] = new double[arraySize];
    return x;
}
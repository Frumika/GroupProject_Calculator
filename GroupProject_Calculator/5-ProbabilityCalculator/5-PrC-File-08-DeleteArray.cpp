#include "5-PrC-File-01-Header.h"

/* Удаление массива */
void deleteArray(double **x)
{
    delete[] x[0];
    delete[] x[1];
    delete[] x;
}
#include "4-CoC-File-01-Header.h"

/* Факториал */
double factorial(int n)
{
    double k = 1;
    for(; n > 0; k *= n, n--);
    return k;
}

/* Степень */
double pow(int n, int m)
{
    double k = 1;
    for(; m > 0; k *= n, m--);
    return k;
}
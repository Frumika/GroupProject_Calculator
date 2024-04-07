#include "3-FuC-File-01-Header.h"

double PolynomFunc(double x, double arr[], int n)
{
    double res = 0;

    for (int i = 0; i < n; i++)
        res += arr[i] * pow(x, arr[i]);

    return res;
}


double DegreeFunc(double x, double a, double b, double c)
{
    return a * pow(x, b) + c;
}

double ExponentFunc(double x, double a, double b, double c, double d)
{
    return a * pow(b, c * x) + d;
}

double LogFunc(double x, double a, double b, double c)
{
    return a * log(b * x) + c;
}

double SinFunc(double x, double a, double b, double c, double d)
{
    return a * sin(b * x + c) + d;
}

double CosFunc(double x, double a, double b, double c, double d)
{
    return a * cos(b * x + c) + d;
}

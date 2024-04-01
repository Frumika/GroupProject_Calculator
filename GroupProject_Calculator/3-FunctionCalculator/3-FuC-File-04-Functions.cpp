#include "3-FuC-File-01-Header.h"

double DegreeFunc(double x, double a, double b, double c, double d)
{
    return a * pow(x, b) + c;
}

double ExponentFunc(double x, double a, double b, double c, double d)
{
    return a * pow(b, c * x) + d;
}

double LogFunc(double x, double a, double b, double c, double d)
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

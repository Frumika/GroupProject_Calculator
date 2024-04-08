#include "5-PrC-File-01-Header.h"

/* Математическое ожидание */
double solveMathExpectation(double **x, int arraySize)
{
    double mathExpectation = 0;
    for(int column = 0; column < arraySize; column++)
    {
        mathExpectation += x[0][column]*x[1][column];
    }
    return mathExpectation;
}

/* Математическое ожидание с квадратами значений (для просчёта дисперсии) */
double solveSquareMathExpectation(double **x, int arraySize)
{
    double squareMathExpectation = 0;
    for(int column = 0; column < arraySize; column++)
    {
        squareMathExpectation += x[0][column]*x[0][column]*x[1][column];
    }
    return squareMathExpectation;
}
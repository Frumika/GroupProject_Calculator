#include "1-MaC-File-01-Header.h"
#include <iostream>

using namespace std;

void runTest()
{
    Matrix* matrixA;
    int n, m;


    cout << "Первая матирца" << endl;

    cout << "Введите размеры матриц: ";
    cin >> n >> m;

    matrixA = enterMatrix(n, m);

    matrixA = findInverseMatrix(matrixA);

    printMatrix(matrixA);
}

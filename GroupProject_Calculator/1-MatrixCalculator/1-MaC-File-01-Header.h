#pragma once
#include "../0-Common/0-Co-File-01-Header.h"
#include "1-MaC-File-02-Matrix.h"

void displayMatrixMenu();

Matrix* enterMatrix(int n, int m);

void printMatrix(Matrix* matrixA);

void clearMatrix(Matrix* matrixA);

Matrix* copyMatrix(Matrix* matrixA);

void sumMatrix(Matrix* matrixA, Matrix* matrixB);
void sumMatrix(Matrix* matrixA, double* number);
void subtractMatrix(Matrix* matrixA, Matrix* matrixB);

Matrix* multiplicationMatrix(Matrix* matrixA, Matrix* matrixB);
void multiplicationMatrix(Matrix* matrixA, double* number);

Matrix* transpositionMatrix(Matrix* matrixA);

Matrix* createStepMatrix(Matrix* matrixA, int* swap);

double* findDeterminant(Matrix* matrixA);

Matrix* createMinor(Matrix* matrixA, int* iA, int* jA);

double findAlgebraicComplement(Matrix* matrixA, int* iA, int* jA);

Matrix* findInverseMatrix(Matrix* matrixA, double* determinant);

void runSumMatrix(bool key);

void runSubMatrix();

void runMultiplicationMatrix(bool key);

void runTranspositionMatrix();

void runDeterminantMatrix();

void runInverseMatrix();

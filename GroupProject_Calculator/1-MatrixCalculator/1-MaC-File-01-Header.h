#pragma once
#include "../0-Common/0-Co-File-01-Header.h"
#include "1-MaC-File-02-Matrix.h"

void displayMatrixMenu();

Matrix* enterMatrix(int, int);

void printMatrix(Matrix*);

void clearMatrix(Matrix*);

Matrix* copyMatrix(Matrix* matrixA);

Matrix* sumMatrix(Matrix*, Matrix*);
Matrix* subtractMatrix(Matrix*, Matrix*);
Matrix* sumMatrix(Matrix*, double*);

Matrix* multiplicationMatrix(Matrix*, Matrix*);
Matrix* multiplicationMatrix(Matrix*, double*);

Matrix* transpositionMatrix(Matrix*);

Matrix* createStepMatrix(Matrix*);

double findDeterminant(Matrix*);

Matrix* createMinor(Matrix*, int*, int*);

double findAlgebraicComplement(Matrix*, int*, int*);

Matrix* findInverseMatrix(Matrix*);


void runTest();

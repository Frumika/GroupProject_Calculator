﻿#include "1-MaC-File-01-Header.h"


/*
 * Функция copyMatrix принимает указатель типа Matrix на матрицу.
 * На основе входящей матрицы функция создаёт новую матрицу, полностью анологичную входящей.
 * Старая (входящая) матрица в результате работы функции не меняется.
 * Функция возвращает указатель на новую матрицу.
 */
Matrix* copyMatrix(Matrix* matrixA)
{
    Matrix* matrixB = new Matrix; // Объявляем новую матрицу

    matrixB->matrix = new double*[*matrixA->n]; // Создаем динамический массив указателей на строки матрицы
    matrixB->n = new int{*matrixA->n}; // Количество строк новой матрицы
    matrixB->m = new int{*matrixA->m}; // Количество столбцов новой матрицы

    for (int i = 0; i < *matrixB->n; i++)
    {
        matrixB->matrix[i] = new double[*matrixB->m]; 
        for (int j = 0; j < *matrixB->m; j++) matrixB->matrix[i][j] = matrixA->matrix[i][j];
    }
    return matrixB; 
}
#pragma once

// Структура описывающая матрицу
struct Matrix
{
    double** matrix; // Указатель на динамический массив указателей
    unsigned short* n; // Количество строк матрицы 
    unsigned short* m; // Количество столбцов матрицы
};

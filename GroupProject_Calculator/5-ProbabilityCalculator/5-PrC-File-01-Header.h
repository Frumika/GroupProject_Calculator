#pragma once


void runProbabilityCalculator();    //Основная функция калькулятора вероятности

void runProbability();  //Для запуска калькулятора вероятности

double solveMathExpectation(double **x, int arraySize); //Просчёт математического ожидания

double solveSquareMathExpectation(double **x, int arraySize);   //Просчёт математического ожидания с квадратами значений

double** createArray(int arraySize);   //Создание двумерного массива

void deleteArray(double **x);   //Удаление двумерного массива

void enterArray(double **x, int arraySize);   //Ввод двумерного массива

void runMathExpectation();   //Для запуска калькулятора мат. ожидания

void runDispersion();   //Для запуска калькулятора дисперсии
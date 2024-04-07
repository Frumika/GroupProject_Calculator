#pragma once


void runProbabilityCalculator();    //Основная функция калькулятора вероятности

void runProbability();  //Для запуска калькулятора вероятности

double solveMathExpectation(double **x, int arraySize); //Просчёт математического ожидания

double solveSquareMathExpectation(double **x, int arraySize);   //Просчёт математического ожидания с квадратами значений

void runDispersion();   //Для запуска калькулятора дисперсии и мат. ожидания по совместимости
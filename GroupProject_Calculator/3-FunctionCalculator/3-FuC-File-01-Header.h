#pragma once

#include <iostream>
#include <conio.h>
#include <functional>

using namespace std;

double DegreeFunc(double x, double a, double b, double c, double d);
double ExponentFunc(double x, double a, double b, double c, double d);
double LogFunc(double x, double a, double b, double c, double d);
double SinFunc(double x, double a, double b, double c, double d);
double CosFunc(double x, double a, double b, double c, double d);
void runSecondFuncMenu(function<double(double)> ChosenFunc);
double runDefIntegral(function<double (double)> ChosenFunc);
void runFuncRootCalc(function<double(double)> ChosenFunc);
#pragma once

//Необходимые инклюды

#include <iostream>
#include <conio.h>
#include <functional>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

// Глобальные переменные для графика

#define WIDTH 800 
#define HEIGHT 600
#define MAX_FONT_SIZE 16

extern bool wasMade;
extern double root;
extern bool goodFunc;

// *Объявление функций

double PolynomFunc(double x, double arr[], int n);
double DegreeFunc(double x, double a, double b, double c);
double ExponentFunc(double x, double a, double b, double c, double d);
double LogFunc(double x, double a, double b, double c);
double SinFunc(double x, double a, double b, double c, double d);
double CosFunc(double x, double a, double b, double c, double d);

void runFunctionCalculator();
void runSecondFuncMenu(function<double(double)> ChosenFunc);
void runDefIntegral(function<double (double)> ChosenFunc);
void runFuncRootCalc(function<double(double)> ChosenFunc);
void runExtremumCalc(function<double (double)> ChosenFunc);

void plot(SDL_Renderer *renderer, int x, int y);
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
void drawText(SDL_Renderer *renderer, TTF_Font *font, int x, int y, const string &text, int fontSize);
void drawAxisLabels(SDL_Renderer *renderer, TTF_Font *font, int fontSize,
    double scaleX, double scaleY, double offsetX, double offsetY);
void renderGraph(SDL_Renderer *renderer, function<double(double)> ChosenFunc, TTF_Font *font, int fontSize,
    double scaleX, double scaleY, double offsetX, double offsetY);
void DrawFunc(function<double (double)> ChosenFunc);
int calculateFontSize(double scaleX);
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

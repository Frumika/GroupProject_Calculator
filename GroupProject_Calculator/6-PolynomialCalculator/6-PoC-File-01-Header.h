#pragma once
#include <algorithm> // sort
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <string>
#include <utility> // pair
#include <vector>
#include <conio.h>
#include<locale.h>
using namespace std;
using Item = pair<double, double>;
using Poly = list<Item>;
vector<double> AllCoef(const Poly* pol, double pwr);
void PrintPolynom(Poly* pol);
void NormPolynom(Poly* pol);
Poly* UmnPolinomNaChislo(Poly* pol1);
Poly* ProizPolynom(Poly* pol1);
Poly* DivPolynom(Poly* pol1, Poly* pol2, Poly** rem);
Poly* AddPolynom(Poly* pol1, Poly* pol2);
Poly* SubtPolynom(Poly* pol1, Poly* pol2);
Poly* MultPolynom(Poly* pol1, Poly* pol2);
Poly* GetPolynom(istream& in);
void runPolynomialCalculator();
void Disclaimer();
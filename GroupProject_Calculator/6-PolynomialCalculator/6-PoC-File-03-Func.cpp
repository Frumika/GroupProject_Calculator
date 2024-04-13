#include"6-PoC-File-01-Header.h"
Poly* UmnPolinomNaChislo(Poly* pol1) {
    setlocale(LC_ALL, "Russian");
    Poly* pol = new Poly;
    double chislo;
    cout << "Введите число, на которое хотите умножить полином\n"; cin >> chislo;
    for (Item& p1 : *pol1) {
        Item itm = make_pair(p1.first, p1.second * chislo);
        if (itm.second != 0)
            pol->emplace_back(itm);
    }
    NormPolynom(pol);
    return pol;
}// умножение полинома на число
Poly* ProizPolynom(Poly* pol1) {
    Poly* pol = new Poly;
    for (Item& p1 : *pol1) {
        if (p1.first > 0) {
            Item itm = make_pair(p1.first - 1, p1.second * p1.first);
            if (itm.second != 0)
                pol->emplace_back(itm);
        }
    }
    NormPolynom(pol);
    return pol;
}//производная первого порядка
Poly* DivPolynom(Poly* pol1, Poly* pol2, Poly** rem) {
    setlocale(LC_ALL, "Russian");
    const double pwr1 = pol1->front().first;
    const double pwr2 = pol2->front().first;
    if (pwr1 < pwr2) { system("cls");cout << "\n Попробуйте ввести полиномы в другом порядке или выберите другой номер задачи \n\n"; return 0;}
    if ((abs(int(pwr1))!=pwr1)&&(abs(int(pwr2))!=pwr2)){cout<<"Напоминаем: операция деления полиномов доступна только для положительных целых показателей степени";return 0;}
    Poly* pol = new Poly;
    *rem = new Poly;
    vector<double> cf1 = AllCoef(pol1, pwr1);
    vector<double> cf2 = AllCoef(pol2, pwr2);
    for (int i = 0; i <= pwr1 - pwr2; ++i) {
        if (cf1[i] == 0) continue;
        // Вычисляем и размещаем коэффициент частного
        double c = cf1[i] / cf2[0];
        int k = pwr1 - i - pwr2;
        pol->emplace_back(make_pair(k, c));
        // Пересчитываем коэффициенты остатка
        cf1[i] = 0;
        for (unsigned j = 1; j < cf2.size(); ++j)
            cf1[i + j] -= cf2[j] * c;
    }
    // Размещаем коэффициенты остатка в полиноме
    double eps = numeric_limits<double>::epsilon();
    for (unsigned i = 1; i < cf1.size(); ++i) {
        if (abs(cf1[i]) > eps)
            (*rem)->emplace_back(make_pair(pwr1 - i, cf1[i]));
    }
    NormPolynom(pol);
    NormPolynom(*rem);
    return pol;
}// деление полиномов

Poly* AddPolynom(Poly* pol1, Poly* pol2) {
    const double pwr1 = pol1->front().first;
    const double pwr2 = pol2->front().first;
    if ((abs(int(pwr1))!=pwr1)&&(abs(int(pwr2))!=pwr2)){system("cls");cout<<"Напоминаем: операция сложения полиномов доступна только для положительных целых показателей степени";return 0;}
    Poly* pol = new Poly;
    double pwr = max(pol1->front().first, pol2->front().first);
    vector<double> cf1 = AllCoef(pol1, pwr);
    vector<double> cf2 = AllCoef(pol2, pwr);
    for (int i = 0; i <= pwr; ++i) {
        Item itm = make_pair(pwr - i, cf1[i] + cf2[i]);
        if (itm.second != 0)
            pol->emplace_back(itm);
    }
    NormPolynom(pol);
    return pol;
}//сложение полиномов

Poly* SubtPolynom(Poly* pol1, Poly* pol2) {
    const double pwr1 = pol1->front().first;
    const double pwr2 = pol2->front().first;
    if ((abs(int(pwr1))!=pwr1)&&(abs(int(pwr2))!=pwr2)){system("cls");cout<<"Напоминаем: операция вычитания полиномов доступна только для положительных целых показателей степени";return 0;}
    Poly* pol = new Poly;
    int pwr = max(pol1->front().first, pol2->front().first);
    vector<double> cf1 = AllCoef(pol1, pwr);
    vector<double> cf2 = AllCoef(pol2, pwr);
    for (int i = 0; i <= pwr; ++i) {
        Item itm = make_pair(pwr - i, cf1[i] - cf2[i]);
        if (itm.second != 0)
            pol->emplace_back(itm);
    }
    NormPolynom(pol);
    return pol;
}// вычитание полиномов

Poly* MultPolynom(Poly* pol1, Poly* pol2) {
    Poly* pol = new Poly;
    for (Item& p1 : *pol1) {
        for (Item& p2 : *pol2) {
            Item itm = make_pair(p1.first + p2.first, p1.second * p2.second);
            if (itm.second != 0)
                pol->emplace_back(itm);
        }
    }
    NormPolynom(pol);
    return pol;
}//перемножение полиномов
void Disclaimer()
{setlocale(LC_ALL, "Russian");
    cout
    << "|----------------------------------------------------|" << endl
    << "|         Ознакомьтесь с правилами пользования:      |" << endl
    << "|----------------------------------------------------|" << endl
    << "| >>Ввод полинома осуществляется следующим образом:  |" << endl
    << "|   Для каждого члена полинома вводится пара чисел,  |" << endl
    << "|   где первое число- степень переменной х,          |" << endl
    << "|   а второе-коэффициент перед переменной.           |" << endl
    << "|   Пары чисел разделяются знаком ';'                |" << endl
    << "| >>Например, полином  3*x^2+2 вводится так: 2 3;0 2 |" << endl
    << "|   Ввод полинома завершается нажатием клавиши Enter |" << endl
    << "|>>Калькулятор работает с целыми степенями для задач:|"<<endl
    << "|   сложение, деление, вычитание полиномов           |" << endl
    << "|----------------------------------------------------|" << endl;
}
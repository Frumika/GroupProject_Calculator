#include"6-PoC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"
void runPolynomialCalculator()
{
    setlocale(LC_ALL, "Russian");
    cout
    << "|-----------------------------------------------------------|" << endl
    << "|     !ВНИМАНИЕ! Ознакомьтесь с правилами пользования:      |" << endl
    << "|-----------------------------------------------------------|" << endl
    << "| >>>Ввод полинома осуществляется следующим образом:        |" << endl
    << "|       Для каждого члена полинома вводится пара чисел,     |" << endl
    << "|       где первое число- степень переменной х,             |" << endl
    << "|       а второе-коэффициент перед переменной.              |" << endl
    << "|       Пары чисел разделяются знаком ';'                   |" << endl
    << "|       Например, полином  3*x^2+2 вводится так:  2 3; 0 2  |" << endl
    << "|       Ввод полинома завершается нажатием клавиши Enter    |" << endl
    << "| >>>Калькулятор работает с положительными целыми степенями |"<<endl
    << "|       для задач: сложение, деление, вычитание полиномов   |" << endl
    << "| >>>Советуем проверять каждый введенный многочлен          |" << endl
    << "|-----------------------------------------------------------|" << endl;
    int t;
    Poly* pol3;
    Poly* pol4;
    char but;
    bool cond;
    do
    {
        cout
        << "|----------------------------------------------------|" << endl
        << "|             >>> Введите номер задачи: <<<          |" << endl
        << "|----------------------------------------------------|" << endl
        << "| 1. Деление одного многочлена на другой             |" << endl
        << "| 2. Сложение многочленов                            |" << endl
        << "| 3. Вычитание многочленов                           |" << endl
        << "| 4. Перемножение многочленов                        |" << endl
        << "| 5. Умножение многочлена на число                   |" << endl
        << "| 6. Нахождение производной I порядка от многочлена  |" << endl
        << "| 0. Выйти в главное меню                            |" << endl
        << "|----------------------------------------------------|" << endl;
        but = _getch();
        
        cond = (but == '1' ||
            but == '2' ||
            but == '3' ||
            but == '4' ||
            but == '5' ||
            but == '6' ||
            but == '0');
    /*}
    while (cond == false);*/
    t=but-'0';
        if (t > 0 && t < 5) {
            cout << "\nВведите первый полином \n";
            Poly* pol1 = GetPolynom(cin);
            NormPolynom(pol1);
            cout << "Многочлен 1\n";
            PrintPolynom(pol1);
            cout << "\n";
            cout << "Введите второй полином \n";
            Poly* pol2 = GetPolynom(cin);
            NormPolynom(pol2);
            cout << "\nМногочлен 2\n";
            PrintPolynom(pol2);
            cout << "\n";
            switch (t)
            {
            case 1:  pol4 = DivPolynom(pol1, pol2, &pol3); if (pol4) { cout << "\nРезультат\n"; PrintPolynom(pol4); } break;
            case 2: pol4 = AddPolynom(pol1, pol2);   if (pol4) { cout << "\nРезультат\n"; PrintPolynom(pol4); } break;
            case 3:  pol4 = SubtPolynom(pol1, pol2);  if (pol4) { cout << "\nРезультат\n"; PrintPolynom(pol4); } break;
            case 4: pol4 = MultPolynom(pol1, pol2);  cout << "\nРезультат\n"; PrintPolynom(pol4); break;
            }
        }//считывается 2 полинома
        if (t > 4 && t < 7) {
            cout << "\nВведите полином \n";
            Poly* pol1 = GetPolynom(cin);
            NormPolynom(pol1);
            cout << "Полином\n";
            PrintPolynom(pol1);
            cout << "\n";
            switch (t)
            {
            case 5:pol4 = UmnPolinomNaChislo(pol1); cout << "\nРезультат\n"; PrintPolynom(pol4);  break;
            case 6:pol4 = ProizPolynom(pol1); cout << "\nРезультат\n"; PrintPolynom(pol4); break;
            }
        }//считывается 1 полином
    }
    while (t!=0);
    if (t==0){runMainMenu();}
}
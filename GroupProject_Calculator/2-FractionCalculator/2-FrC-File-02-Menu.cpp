#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "2-FrC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"

void runFractionCalculator()
{
    char choice;
    bool condition;
    
    int uppernum, undernum;
    char input[100];
    
        
    printf("|--------------------------------------------|\n");
    printf("|           >>> Обычные дроби <<<            |\n");
    printf("|--------------------------------------------|\n");
    printf("| 1. Сложение дробей                         |\n");                  
    printf("| 2. Вычитание дробей                        |\n");   
    printf("| 3. Умножение дробей                        |\n");   
    printf("| 4. Деление дробей                          |\n");   
    printf("| 5. Сравнение дробей                        |\n");   
    printf("| 6. Сокращение дробей                       |\n");   
    printf("| 7. В десятичное число                      |\n");
    printf("| 0. Выход                                   |\n");
    printf("|--------------------------------------------|\n");
        
    do
    {
        choice = _getch();
        
        condition = (choice == '1' ||
            choice == '2' ||
            choice == '3' ||
            choice == '4' ||
            choice == '5' ||
            choice == '6' ||
            choice == '7' ||
            choice == '0');
    }
    while (condition == false);

    switch(choice)
    {
    
    case '1':
        system("cls");
        Adding_fractions();
        break;
    case '2':
        system("cls");
        Subtraction_of_fractions();
        break;
    case '3':
        system("cls");
        Multiplication_of_fractions();
        break;
    case '4':
        system("cls");
        Division_of_fractions();
        break;
    case '5':
        system("cls");
        Comparing_fractions();
        break;
    case '6':
        system("cls");
        Call_reduction_func();
        break;
    case '7':
        system("cls");
        Fraction_to_the_decimal_system();
        break;
    default:
        {
            system("cls");
            printf("|----------------------------------------------|\n"); 
            printf("|     >>> Работа калькулятора завершена <<<    |\n"); 
            printf("|----------------------------------------------|\n"); 
            runMainMenu();
        }
    }
}
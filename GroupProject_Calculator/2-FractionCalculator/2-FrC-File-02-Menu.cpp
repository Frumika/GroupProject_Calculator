#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "2-FrC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"
void runFractionCalculator()
{
    int choice=0;
    int uppernum, undernum;
    char input[100];
    do
    {
        printf("|-----------------------------------------------------------|\n");
        printf("|         >>>  Калькулятор обыкновенных дробей  <<<         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("| 1. Сложение дробей                                        |\n");                  
        printf("| 2. Вычитание дробей                                       |\n");   
        printf("| 3. Умножение дробей                                       |\n");   
        printf("| 4. Деление дробей                                         |\n");   
        printf("| 5. Сравнение дробей                                       |\n");   
        printf("| 6. Сокращение дробей                                      |\n");   
        printf("| 7. Представление дроби в виде десятичного числа           |\n");
        printf("| 0. В главное меню                                         |\n");
        printf("|-----------------------------------------------------------|\n");
        
        fgets(input, sizeof(input), stdin);

        if (!isdigit(input[0])) {
            printf("Ошибка. Введите число от 0 до 7.\n");
            continue;
        }

        choice = strtol(input,NULL,10);

        if (choice < 0 || choice > 7) {
            printf("Ошибка. Введите число от 0 до 7.\n");
            continue;
        }

        switch(choice) {
        case 0:
            runMainMenu();
            break;
        case 1:
            Adding_fractions();
            break;
        case 2:
            Subtraction_of_fractions();
            break;
        case 3:
            Multiplication_of_fractions();
            break;
        case 4:
            Division_of_fractions();
            break;
        case 5:
            Comparing_fractions();
            break;
        case 6:
            Call_reduction_func();
            break;
        case 7:
            Fraction_to_the_decimal_system();
            break;
        default:
            printf("Ошибка\n");
        }
    }
    while(choice != 0);
    
}
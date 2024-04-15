#include <stdio.h>

#include "2-FrC-File-01-Header.h"
#include "../0-Common/0-Co-File-01-Header.h"

void Comparing_fractions()
{
    printf("|------------------------------------------------|\n");
    printf("|            >>> Сравнение дробей <<<            |\n");
    printf("|------------------------------------------------|\n");
    
    double fraction1, fraction2;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    int denominator2,nominator2; // для 2 дроби
    printf("Введите числитель и знаменатель 1 дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    printf("Введите числитель и знаменатель 2 дроби: \n");scanf_s("%d %d",&nominator2,&denominator2);
    if((denominator1)!=0 && (denominator2)!=0)
    {
        fraction1=(nominator1*1.0/denominator1);
        fraction2=(nominator2*1.0/denominator2);
        if (fraction1>fraction2)
        {
            printf("| Ответ: %d / %d > %d / %d \n",nominator1,denominator1,nominator2,denominator2);
            printf("\n");
        }
        if(fraction1<fraction2)
        {
            printf("| Ответ: %d / %d < %d / %d \n",nominator1,denominator1,nominator2,denominator2);
            printf("\n");
        }
        if(fraction1==fraction2)
        {
            printf("| Ответ: %d / %d = %d / %d \n",nominator1,denominator1,nominator2,denominator2);
            printf("\n");
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
    runFractionCalculator();
}
////////////////////////////////
void Call_reduction_func()
{
    printf("|------------------------------------------------|\n");
    printf("|            >>> Сокращение дроби <<<            |\n");
    printf("|------------------------------------------------|\n");
    
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    printf("Введите числитель и знаменатель сокращаемой дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    if((denominator1)!=0)
    {
        int *result = Fraction_reduction(nominator1,denominator1);
        int flag=4;
        if(denominator1==nominator1)
        {
            flag=1;
            printf("| Ответ: %d / %d = %d \n",nominator1,denominator1,1);
            printf("\n");
        }
        if((denominator1==(-1*nominator1) || nominator1==(-1*denominator1)))
        {
            flag=2;
            printf("| Ответ: %d / %d = %d \n",nominator1,denominator1,-1);
            printf("\n");
        }
        if(nominator1==0)
        {
            flag=3;
            printf("| Ответ: %d / %d = %d \n",nominator1,denominator1,0);
            printf("\n");
        }
        if(denominator1<0 && nominator1<0 && flag==4)
        {
            flag=5;
            printf("| Ответ: %d / %d = %d / %d \n",nominator1,denominator1,-1*result[0],-1*result[1]);
            printf("\n");
        }
        if(flag==4)
        {
            printf("| Ответ: %d / %d = %d / %d \n",nominator1,denominator1,result[0],result[1]);
            printf("\n");
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
    runFractionCalculator();
}
////////////////////////////////
void Fraction_to_the_decimal_system()
{
    printf("|------------------------------------------------|\n");
    printf("|        >>> Дробь в десятичное число <<<        |\n");
    printf("|------------------------------------------------|\n");
    
    double decimal=0;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    printf("Введите числитель и знаменатель переводимой дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    if((denominator1)!=0)
    {
        if(denominator1!=nominator1)
        {
            decimal += (float) nominator1 / (float) denominator1;
            printf("| Ответ: %d / %d = %lf \n",nominator1,denominator1,decimal);
            printf("\n");
        }
        else{printf("| Ответ: %d / %d = 1 \n",nominator1,denominator1);
            printf("\n");}
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
    runFractionCalculator();
}
#include <stdio.h>

#include "2-FrC-File-01-Header.h"

void Comparing_fractions()
{
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
            printf(" %d / %d > %d / %d\n",nominator1,denominator1,nominator2,denominator2);
        }
        if(fraction1<fraction2)
        {
            printf(" %d / %d < %d / %d\n",nominator1,denominator1,nominator2,denominator2);
        }
        if(fraction1==fraction2)
        {
            printf(" %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
////////////////////////////////
void Call_reduction_func()
{
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    printf("Введите числитель и знаменатель сокращаемой дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    if((denominator1)!=0)
    {
        int *result = Fraction_reduction(nominator1,denominator1);
        int flag=4;
        if(denominator1==nominator1)
        {
            flag=1;
            printf(" %d / %d = %d\n",nominator1,denominator1,1);
        }
        if((denominator1==(-1*nominator1) || nominator1==(-1*denominator1)))
        {
            flag=2;
            printf(" %d / %d = %d\n",nominator1,denominator1,-1);
        }
        if(nominator1==0)
        {
            flag=3;
            printf(" %d / %d = %d\n",nominator1,denominator1,0);
        }
        if(denominator1<0 && nominator1<0 && flag==4)
        {
            flag=5;
            printf(" %d / %d = %d / %d\n",nominator1,denominator1,-1*result[0],-1*result[1]);
        }
        if(flag==4)
        {
            printf(" %d / %d = %d / %d\n",nominator1,denominator1,result[0],result[1]);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
////////////////////////////////
void Fraction_to_the_decimal_system()
{
    double decimal=0;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    printf("Введите числитель и знаменатель переводимой дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    if((denominator1)!=0)
    {
        if(denominator1!=nominator1)
        {
            decimal += (float) nominator1 / (float) denominator1;
            printf(" %d / %d = %lf\n",nominator1,denominator1,decimal);
        }
        else{printf(" %d / %d = 1\n",nominator1,denominator1);}
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
#include <stdio.h>

#include "2-FrC-File-01-Header.h"

void Multiplication_of_fractions()
{
    int uppernum,undernum;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    int denominator2,nominator2; // для 2 дроби
    printf("Введите числитель и знаменатель 1 дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    printf("Введите числитель и знаменатель 2 дроби: \n");scanf_s("%d %d",&nominator2,&denominator2);
    if((denominator1)!=0 && (denominator2)!=0)
    {
        undernum = denominator1*denominator2;
        uppernum = nominator1*nominator2;
        int *result = Fraction_reduction(uppernum,undernum);
        int flag=4;
        if(undernum==uppernum)
        {
            flag=1;
            printf(" %d / %d * %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,1);
        }
        if((undernum==(-1*uppernum) || uppernum==(-1*undernum)))
        {
            flag=2;
            printf(" %d / %d * %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,-1);
        }
        if(uppernum==0)
        {
            flag=3;
            printf(" %d / %d * %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,0);
        }
        if(flag==4)
        {
            printf(" %d / %d * %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2,result[0],result[1]);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
////////////////////////////
void Division_of_fractions()
{
    int uppernum,undernum;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    int denominator2,nominator2; // для 2 дроби
    printf("Введите числитель и знаменатель 1 дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    printf("Введите числитель и знаменатель 2 дроби: \n");scanf_s("%d %d",&nominator2,&denominator2);
    if((denominator1)!=0 && (denominator2)!=0)
    {
        undernum = denominator1 * nominator2;
        uppernum = nominator1 * denominator2;
        int *result = Fraction_reduction(uppernum,undernum);
        int flag=4;
        if(undernum==uppernum)
        {
            flag=1;
            printf(" %d / %d : %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,1);
        }
        if((undernum==(-1*uppernum) || uppernum==(-1*undernum)))
        {
            flag=2;
            printf(" %d / %d : %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,-1);
        }
        if(uppernum==0)
        {
            flag=3;
            printf(" %d / %d : %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,0);
        }
        if(undernum<0 && uppernum<0)
        {
            flag=5;
            printf(" %d / %d : %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2,-1*result[0],-1*result[1]);
        }
        if(undernum==1)
        {
            flag=6;
            printf(" %d / %d : %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,result[0]);
        }
        if(flag==4)
        {
            printf(" %d / %d : %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2,result[0],result[1]);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

#include "2-FrC-File-01-Header.h"

int *Fraction_reduction(int &uppernum, int &undernum)
{
    int result[2];
    int i=0;
    int prime_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    result[0]=uppernum;
    result[1]=undernum;
    while(i<8)
    {
        
        if ((undernum % prime_numbers[i] == 0) && (uppernum % prime_numbers[i] == 0))
        {
            
            uppernum = uppernum / prime_numbers[i];
            undernum = undernum / prime_numbers[i];
            result[0]=uppernum;
            result[1]=undernum;
            if(undernum==uppernum)
            {
                result[0]=1;
                result[1]=1;
                return result;
            }
        }
        else{i++;}
    }
    return result;
}
///////////////////////////////////////////////////////////
void Adding_fractions()
{
    int uppernum,undernum;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    int denominator2,nominator2; // для 2 дроби
    printf("Введите числитель и знаменатель 1 дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    printf("Введите числитель и знаменатель 2 дроби: \n");scanf_s("%d %d",&nominator2,&denominator2);
    
    if((denominator1)!=0 && (denominator2)!=0)
    {
        undernum = denominator1*denominator2;
        uppernum = ((nominator1*denominator2)+(nominator2*denominator1));
        int *result = Fraction_reduction(uppernum,undernum);
        int flag=4;
        if(undernum==uppernum)
        {
            flag=1;
            printf(" %d / %d + %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,1);
        }
        if((undernum==(-1*uppernum) || uppernum==(-1*undernum)))
        {
            flag=2;
            printf(" %d / %d + %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,-1);
        }
        if(uppernum==0)
        {
            flag=3;
            printf(" %d / %d + %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,0);
        }
        if(flag==4)
        {
            printf(" %d / %d + %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2,result[0],result[1]);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
/////////////////////////////////////////////////////
void Subtraction_of_fractions()
{
    int uppernum,undernum;
    int denominator1,nominator1; // знаменатель и числитель для 1 дроби
    int denominator2,nominator2; // для 2 дроби
    printf("Введите числитель и знаменатель 1 дроби: \n");scanf_s("%d %d",&nominator1,&denominator1);
    printf("Введите числитель и знаменатель 2 дроби: \n");scanf_s("%d %d",&nominator2,&denominator2);
    if((denominator1)!=0 && (denominator2)!=0)
    {
        undernum = denominator1*denominator2;
        uppernum = nominator1*denominator2-nominator2*denominator1;
        int *result = Fraction_reduction(uppernum, undernum);
        int flag=4;
        if(undernum==uppernum)
        {
            flag=1;
            printf(" %d / %d - %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,1);
        }
        if((undernum==(-1*uppernum) || uppernum==(-1*undernum)))
        {
            flag=2;
            printf(" %d / %d - %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,-1);
        }
        if(uppernum==0)
        {
            flag=3;
            printf(" %d / %d - %d / %d = %d\n",nominator1,denominator1,nominator2,denominator2,0);
        }
        if(flag==4)
        {
            printf(" %d / %d - %d / %d = %d / %d\n",nominator1,denominator1,nominator2,denominator2,result[0],result[1]);
        }
    }
    else{printf("Ошибка деления на ноль!\n");}
    getchar();
}
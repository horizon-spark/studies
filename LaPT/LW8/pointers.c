/* pointers.c
---------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 02.05.2024
-------------------------------------------------------------------------------------------
1) Создание массива из 10 неотрицательных целых чисел и вывод его на экран.
2) Вычисление среднего геометрического данного массива и вывод его на экран.
3) Создание двумерного массива ненулевых целых чисел и вывод его на экран.
4) Вычисление количества смен знака при просматривании массива сверху вниз и слева направо.
5) Вывод на экран результатов теста.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define M 10

void random_1(int*,int,int,int);
void random_2(int(*)[M],int,int,int,int);
void aver_geom(int*,int);
void count_sign_change(int(*)[M],int,int);
void print_1(int*,int); 
void print_2(int(*)[M],int,int);  
             
int main()
{
    const int len = N,rows = N,colomns = M;
    int array_1[N], array_2[N][M];
    int *arr_1 = array_1, (*arr_2)[M] = array_2;
    
    printf("Task 1:\n");
    random_1(arr_1,len,50,1);
    print_1(arr_1,len);
    printf("Geometric mean of the array is: ");
    aver_geom(arr_1,len);

    printf("Task 2:\n");
    random_2(arr_2,rows,colomns,100,-50);
    print_2(arr_2,rows,colomns);
    printf("Total changes of the sign: ");
    count_sign_change(arr_2,rows,colomns);

    // Тест: 

    printf("Test (1):\n");
    printf("1) Array of zeros (expected result is 0)\nResult: ");
    random_1(arr_1,len,1,0);
    aver_geom(arr_1,len);
    printf("2) Array of ones (expected result is 1)\nResult: ");
    random_1(arr_1,len,1,1);
    aver_geom(arr_1,len);
    printf("3) Array of numbers 2 (expected result is 32)\nResult: ");
    random_1(arr_1,len,1,2);
    aver_geom(arr_1,len); 

    printf("Test (2):\n");
    printf("1) Array of positive numbers (expected 0)\nResult: ");
    random_2(arr_2,rows,colomns,50,1);
    count_sign_change(arr_2,rows,colomns);
    printf("2) Array of negative numbers (expected 0)\nResult: ");
    random_2(arr_2,rows,colomns,50,-51);
    count_sign_change(arr_2,rows,colomns);

    return 0;
}

void random_1(int *arr,int len,int range,int min)
{
    for (int i=0;i<len;i++) {
        *(arr+i)=rand()%range + min;
    }
}

void random_2(int (*arr)[M],int rows,int colomns,int range,int min)
{
    for (int i=0;i<rows;i++) {
        for (int j=0;j<colomns;j++) {
            *(*(arr+i)+j)=rand()%range + min;
            if (*(*(arr+i)+j)==0) 
                *(*(arr+i)+j)=rand()%10 + 5;
        }
    }
}

void aver_geom(int *arr,int len)
{
    double expr=1;
    int i=0;
    while (i<len) {
        expr*=*(arr+i);
        i++;
    }
    expr = sqrt(expr);
    printf("%lf\n",expr);                                                 
}

void count_sign_change(int (*arr)[M],int rows,int colomns)
{
    short next_sign,changes=0;
    short current_sign = *(*arr)>0 ? 1:0;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<colomns;j++) { 
            next_sign = *(*(arr+i)+j)>0 ? 1:0;
            if (next_sign!=current_sign) {
                current_sign=next_sign;
                changes+=1;
            }
        }
    }
    printf("%d\n",changes);                                                 
}

void print_1(int *arr,int len)
{
    for (int i=0;i<len;i++) {
        printf("%d\t",*(arr+i));
    }
    printf("\n"); 
}

void print_2(int (*arr)[M],int rows,int colomns)
{
    for (int i=0;i<rows;i++) {
        for (int j=0;j<colomns;j++) {
            printf("%d\t",*(*(arr+i)+j));
            if (j==colomns-1) 
                printf("\n"); 
        }
    }  
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void random_1(int*,int,int,int);
void aver_geom(int*,int);

int main()
{
    const int len = 10;
    int arr_1[10];
    
    random_1(arr_1,len,50,1);
    for (int i=0;i<len;i++) {
        printf("%d\t",*(arr_1+i));
    }
    printf("\n");
    aver_geom(arr_1,len);
}

void random_1(int *arr,int len,int range,int min)
{
    for (int i=0;i<len;i++) {
        *(arr+i)=rand()%range + min;
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
    printf("Geometric mean of the array is: %lf",expr);
}
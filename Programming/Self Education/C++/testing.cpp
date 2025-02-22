#include <iostream>
#include <math.h>

void pow(double *a,int b)
{
    double result{1};
    if (b>=0)
    {
        for (int i=0;i<b;i++) 
        {
            result *= *a;
        }
    }
    else 
    {
        for (int i=0;i>b;i--)
        {
            result /= *a;
        }
    }
    *a = result;
    
}

void substract(double *a,int b)
{
    *a = *a - b;
}

void sum(double *a,int b)
{
    *a += b;
}

// int substract(int a)

int main()
{
    double a{5.0};
    int b{2};
    void (*operations[3]) (double*,int) = {pow,substract,substract};
    for (unsigned i=0;i<3;i++)
    {
        operations[i](&a,b);
    }
    std::cout << a << std::endl;
}
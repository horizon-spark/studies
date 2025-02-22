#include <stdio.h>

typedef int (binary)(int,int);
int sum(int,int);
int sub(int,int);
int mult(int,int);
int operation(binary*,int,int);
binary *choose(int);

int main() 
{
    printf("%d",operation(choose(1),7,5));
}

int operation (binary *op,int a,int b)
{
    return op(a,b);
}

binary *choose(int n)
{
    switch(n) 
    {
        case 1: 
            return &sub;
            break;
        case 2:
            return &mult;
            break;
        default: 
            return &sum;
            break;
    }
}

int sum (int a,int b)
{
    return a+b;
}

int sub (int a,int b)
{
    return a-b;
}

int mult (int a,int b)
{
    return a*b;
}
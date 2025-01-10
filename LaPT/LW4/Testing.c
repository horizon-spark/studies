#include <stdio.h>
#include <math.h>

int main()
{
    double x,y;
    printf("Input an argument\n");
    scanf("%lf",&x);
    y = pow(x,2);
    printf("The value of argument is %lf\n",x);
    printf("The value of function is %lf",y);
}
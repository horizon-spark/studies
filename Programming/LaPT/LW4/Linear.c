/* Linear.c
---------------------------
(c)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 31.01.2024
-------------------------------------------
1) Вычисление функции в точке, полученной от пользователя, и вывод этого значения на экран.
2) Вывод на экран результатов теста программы. */

#include <stdio.h>
#include <math.h>

double function(double x)
{
    return (3+exp(x-1))/(pow(x,2)+fabs(1-cos(x)/sin(x)));
}

int main()
{
    double arg,res;
    const double eps = 0.001; // Желаемая точность вычислений
    printf("Input an argument (x):\n");
    scanf("%lf",&arg);
    res = function(arg);
    printf("The value of function is %lf\n",res);

    printf("Test:\n");
    printf("Given value (x) | Given value (y) | Calculated value | Error \n");
    printf("%15lf | %15lf | %16lf | %7lf < eps = 0.001\n",-0.839,1.214,function(-0.839),fabs(function(-0.839)-1.214));
    printf("%15lf | %15lf | %16lf | %7lf < eps = 0.001\n",0.0,0.0,function(0.0),fabs(function(0.0)-0.0));
    printf("%15lf | %15lf | %16lf | %7lf < eps = 0.001\n",0.785,6.169,function(0.785),fabs(function(0.785)-6.169));
    printf("%15lf | %15lf | %16lf | %7lf < eps = 0.001\n",6.102,3.83,function(6.102),fabs(function(6.102)-3.83));
    printf("%15lf | %15lf | %16lf | %7lf < eps = 0.001\n",9.311,42.214,function(9.311),fabs(function(9.311)-42.214));
    return 0;
}
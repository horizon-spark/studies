/* functions.c
-------------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 12.05.2024
----------------------------------------------------------------------------
1) Считывание количества звезд для вывода, вывод заданного количества звезд на экран.
2) Последовательное считывание элементов матрицы 2Х2, вычисление её определителя и вывод результата на экран.
3) Считывание числа итераций для вычисления частичной суммы ряда, вычисление частичной суммы итерационным и 
рекурсивным методом, вывод результата на экран.
4) Вывод на экран результата тестов. 
*/
#include <stdio.h>
#include <math.h>

void print_stars(double);
double count_det(double [2][2]);
double partial_sum_iter(double);
double partial_sum_recur(double);
void test_sum(double);

double input_stars()
{
    double n;
    printf("Input the number of stars: ");
    scanf("%lf",&n);
    return n;
}

int main()
{
    // Задание 1 
    printf("\t Task 1\n");
    print_stars(input_stars());

    // Задание 2
    printf("\n\t Task 2\n");
    double matrix[2][2];
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            printf("Input element a%d%d: ",i+1,j+1);
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("Value of determinant: %lf\n",count_det(matrix));

    // Задание 3 
    printf("\t Task 3\n");
    double k,a;
    printf("Input the value of k (k>=1): ");
    scanf("%lf",&k);
    if (k<1) {
        printf("Incorrect input: k<1\n");
    } else if (modf(k,&a)!=0) {
        printf("Incorrect input: k has a fractional part\n");
    } else {
        printf("Iterational method: %lf\n",partial_sum_iter(k));
        printf("Recursive method: %lf\n",partial_sum_recur(k));
    }           

    // Тест 
    printf("\tTest\n");

    printf("1) Task 1\n");
    printf("a) Number of stars is zero, n=0 (expected result: no stars will be shown)\n");
    print_stars(0);
    printf("\nb) Number of stars is less than zero, n=-3 (expected result: error - incorrect input)\n");
    print_stars(-3);
    printf("c) Number of stars has a fractional part, n=3.2 (expected result: error - incorrect input)\n");
    print_stars(3.2);
    printf("d) Number of stars is more than zero and has no fractional part, n=5 (expected result: 5 stars)\n");
    print_stars(5);

    printf("\n2) Task 2\n");
    printf("a) All elements are zeros, {{0,0},{0,0}} (expected result: 0)\n");
    double matrix_t1[2][2] = {{0,0},{0,0}};
    printf("Result: %lf\n",count_det(matrix_t1));
    printf("b) Matrix with the same elements, {{7,7},{7,7}} (expected result: 0)\n");
    double matrix_t2[2][2] = {{7,7},{7,7}};
    printf("Result: %lf\n",count_det(matrix_t2)); 
    printf("c) Random elements without a fractional part, {{2,-5},{3,-5}} (expected result: 5)\n");
    double matrix_t3[2][2] = {{2,-5},{3,-5}};
    printf("Result: %lf\n",count_det(matrix_t3)); 
    printf("d) Random elements with a fractional part, {{2.5,-3.2},{4.3,5.6}} (expected result: 27.76)\n");
    double matrix_t4[2][2] = {{2.5,-3.2},{4.3,5.6}};
    printf("Result: %lf\n",count_det(matrix_t4)); 

    printf("3) Task 3\n");
    printf("a) k is less than 1, k=0 (expected result: error - incorrect input)\n");
    test_sum(0);
    printf("b) k has a fractional part, k=4.3 (expected result: error - incorrect input)\n");
    test_sum(4.3);
    printf("c) k satisfies nessesary conditions, k=6 (expected result: 2.238259)\n");
    test_sum(6);

    return 0;
}

void print_stars(double n)
{
    double a; // a - переменная для целой части числа, которая сама по себе нигде не используется, но нужна для использования функции modf()
    if (n < 0) 
        printf("Incorrect input: number of stars is less than zero.\n");
    else if (modf(n,&a) != 0) 
        printf("Incorrect input: number of stars has a fractional part.\n");  
    else {
        printf("Result: ");
        for (int i=0;i<n;i++) {
            printf("*");
        } 
    }
    // printf("\n");
}

double count_det(double matrix[2][2])
{
    return (matrix[0][0] * matrix [1][1]) - (matrix[1][0] * matrix [0][1]);
}

double partial_sum_iter(double k)
{
    double a,sum = 0;
    if (k<1) {
        printf("incorrect input: k<1\n");
    } else if (modf(k,&a)!=0) {
        printf("incorrect input: k has a fractional part\n");
    } else {
        for (unsigned i=1;i<=k;i++) {
            sum += pow(i,2)/pow(i+2,2);
        }
    }   
    return sum;
}

double partial_sum_recur(double k)
{
    double a,sum = 0;
    if (k<1) {
        printf("incorrect input: k<1\n");
    } else if (modf(k,&a)!=0) {
        printf("incorrect input: k has a fractional part\n");
    } else {
        if (k != 1) 
            sum = pow(k,2)/pow(k+2,2) + partial_sum_recur(k-1);
        else 
            sum = pow(k,2)/pow(k+2,2);
    }
    return sum;
}

void test_sum(double k)
{
    printf("Iterational method: ");
    printf("Sum = %lf\n",partial_sum_iter(k));
    printf("Recursive method: ");
    printf("Sum = %lf\n",partial_sum_recur(k));
}
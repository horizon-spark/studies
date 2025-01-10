/* in_out.c
------------------------
(с)оздал: Кадарметов Д.Н.
группа  : БИВТ-ВП-23
дата    : 06.04.2024
--------------------------------------------------------------------------------------------------------------------------------
1) Вычисление наибольшего четного положительного числа среди четырех чисел, полученных от пользователя, без использования циклов.
2) Вывод на экран результатов теста программы.
*/
#include <stdio.h>

void if_else(int a,int b,int c,int d);
void sort_2(int a,int b);
void sort_3(int a,int b,int c);
void sort_4(int a,int b,int c,int d);
void print(int a,int b,int c,int d); 

int main()
{
    int a,b,c,d;

    printf("Insert number a:\n");
    scanf("%d",&a);
    printf("Insert number b:\n");
    scanf("%d",&b);
    printf("Insert number c:\n");
    scanf("%d",&c);
    printf("Insert number d:\n");
    scanf("%d",&d);

    printf("Max unsigned even number is: ");
    if_else(a,b,c,d);

    /* В тесте необходимо рассмотреть всевозможные варианты чисел, которые может ввести пользователь. Всего их 16: если все четыре переменные удовлетворяют условию четности
    и положительности - 1 вариант, если 3 переменные - 4 варианта (т.е С из 4 по 3), если 2 переменные - 6 вариантов (т.е. С из 4 по 2), если 1 переменная - 4 варианта,
    если 0 переменных - 1 вариант.*/

    printf("\n\tTest\n+--------------------------------------------------+\n");
    printf("|  a   |   b   |   c   |   d   | Max even unsigned |\n");
    printf("+--------------------------------------------------+");
    print(24,2,6,14);                       // abcd |
    print(2,12,8,-22);                      // abc  |
    print(6,12,-32,30);                     // abd  |
    print(22,-26,10,2);                     // acd  |
    print(-25,18,22,10);                    // bcd  |
    print(6,4,-8,-11);                      // ab   |
    print(8,0,12,-3);                       // ac   |   Параметры, соответствующие условию четности и положительности
    print(2,-2,9,4);                        // ad   |
    print(-10,6,4,13);                      // bc   |
    print(13,10,-12,12);                    // bd   |
    print(0,-12,14,4);                      // cd   |
    print(8,13,-29,-20);                    // a    |
    print(0,18,-3,-4);                      // b    |
    print(15,-17,14,-16);                   // c    |
    print(3,0,-5,2);                        // d    |
    print(0,-3,-4,-10);                     // -    |

    return 0;     
}  

void if_else(int a,int b,int c,int d)
{
    if (a%2==0 && a>0 && b%2==0 && b>0 && c%2==0 && c>0 && d%2==0 && d>0) {
        sort_4(a,b,c,d);
    } else if (a%2==0 && a>0 && b%2==0 && b>0 && c%2==0 && c>0) {
        sort_3(a,b,c);
    } else if (a%2==0 && a>0 && b%2==0 && b>0 && d%2==0 && d>0) {
        sort_3(a,b,d);
    } else if (a%2==0 && a>0 && c%2==0 && c>0 && d%2==0 && d>0) {
        sort_3(a,c,d);
    } else if (b%2==0 && b>0 && c%2==0 && c>0 && d%2==0 && d>0) {
        sort_3(b,c,d);
    } else if (a%2==0 && a>0 && b%2==0 && b>0) {
        sort_2(a,b);
    } else if (a%2==0 && a>0 && c%2==0 && c>0) {
        sort_2(a,c);
    } else if (a%2==0 && a>0 && d%2==0 && d>0) {
        sort_2(a,d);
    } else if (b%2==0 && b>0 && c%2==0 && c>0) {
        sort_2(b,c);
    } else if (b%2==0 && b>0 && d%2==0 && d>0) {
        sort_2(b,d);
    } else if (c%2==0 && c>0 && d%2==0 && d>0) {
        sort_2(c,d);
    } else if (a%2==0 && a>0) {
        printf("%d",a);
    } else if (b%2==0 && b>0) {
        printf("%d",b);
    } else if (c%2==0 && c>0) {
        printf("%d",c);
    } else if (d%2==0 && d>0) {
        printf("%d",d);
    } else {
        printf("-");
    }   
}

void sort_4(int a,int b,int c,int d) 
{
    if (a>b) {
        if (a>c) {
            if (a>d) {
                printf("%d",a);
            } else {
                printf("%d",d);
            }
        } else if (c>d) {
            printf("%d",c);
        } else {
            printf("%d",d);
        }
    } else if (b>c) {
        if (b>d) {
            printf("%d",b);
        } else {
            printf("%d",d);
        }
    } else {
        if (c>d) {
            printf("%d",c);    
        } else {
            printf("%d",d);
        }
    }
}

void sort_3(int a,int b,int c) 
{
    if (a>b) {
        if (a>c) {
            printf("%d",a);
        } else {
            printf("%d",c);
        }
    } else if (b>c) {
        printf("%d",b);
    } else { 
        printf("%d",c);
    }
}

void sort_2(int a,int b)
{
    if (a>b) {
        printf("%d",a);
    } else {
        printf("%d",b);
    }
}

void print(int a,int b,int c,int d) 
{
    printf("\n|%5d | %5d | %5d | %5d | \t  ",a,b,c,d);
    if_else(a,b,c,d);
    if ((a==6 && b==4) || (a==2 && b==-2) || a==-10 || (a==8 && b==13) || a==3 || (a==0 && b==-3)) {
        printf("        |\n");
        printf("+--------------------------------------------------+");
    } else {
        printf("       |\n");
        printf("+--------------------------------------------------+");
    }
    
}
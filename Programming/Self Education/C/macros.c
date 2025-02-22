#include <stdio.h>
#define N 22
#define max(a,b) (a>b ? a : b)

// int main()
// {
//     int x = N;
//     printf("%d",x);
//     #undef N
//     return 0;
// }

int main()
{
    int i;
    i=max(5,10);
    printf("%d",i);
    return 0;
}
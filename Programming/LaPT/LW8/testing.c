#include <stdio.h>
#define M 2
#define N 2

int main()
{
    int array[2][2] = {{1,2},{3,4}};
    int (*arr)[2] = array;
    for (int i=0;i<M;i++)
    {
        for (int j=0;j<N;j++)
        {
            *(*(arr+i)+j) = i + j;
            if (j==N-1)
            {
                printf("%d\n",*(*(arr+i)+j));
            }
            else
            {
                printf("%d",*(*(arr+i)+j));
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // malloc()

    // double *ptr_d = malloc(sizeof(double));
    // long *ptr_l = malloc(sizeof(ptr_l));
    // *ptr_d = 1.989;
    // *ptr_l = 20;
    // printf("Double number: %lf\nLong number: %ld",*ptr_d,*ptr_l);
    // free(ptr_d);
    // free(ptr_l); 

    // calloc()

    // long *p_long = calloc(5,sizeof(long));
    // if (p_long)
    // {
    //     for (int i=0;i<5;i++)
    //     {
    //         *(p_long+i) = 1+i;
    //         printf("Array[%d] = %ld\n",i,*(p_long+i));
    //     }
    // }
    // free(p_long);

    // realloc()

    // long *p_long = calloc(3,sizeof(long));
    // if (p_long)
    // {
    // for (int i=0;i<3;i++)
    // {
    //     *(p_long+i)=i+1;
    //     printf("%ld\t",*(p_long+i));
    // }
    // p_long = realloc(p_long,5*sizeof(long));
    // for (int i=3;i<5;i++)
    // {
    //     *(p_long+i)=i+1;
    //     printf("%ld\t",*(p_long+i));
    // }
    // }
    // free(p_long);

    //unknown size:

    unsigned short len;
    printf("Input array length: ");
    scanf("%u",&len);
    int *ptr=calloc(len,sizeof(int));
    if (ptr) 
    {
        for (int i=0;i<len;i++)
        {
            printf("Input array[%d]: ",i);
            scanf("%d",ptr+i);
        }
        for (int i=0;i<len;i++)
        {
            printf("%d\t",*(ptr+i));
        }
    }
    else 
        printf("Error of allocation");
    


}

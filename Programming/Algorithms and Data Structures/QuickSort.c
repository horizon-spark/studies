#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int mass[], int l, int r){
int i = l - 1, j = r, v = mass[r], buf;
for( ; ; ) {
while(mass[++i] < v);
while(v < mass[--j])
if (j == l) break;
if(i >= j) break;
buf = mass[i]; mass[i] = mass[j]; mass[j] = buf;
}
buf = mass[i]; mass[i] = mass[r]; mass[r] = buf;
return i;
}
void quickSort(int mass[], int l, int r){
if(r <= l) return;
int i = partition(mass, l, r);
quickSort(mass, l, i - 1);
quickSort(mass, i + 1, r);
return;
}
int main(void)
{
int n = 0;
srand(time(NULL));
printf("Enter the array size: ");
scanf("%d", &n);
int array[n];
printf("\nThe generated array:\n");
for(int i = 0; i < n; i++)
{
array[i] = rand() % 101 - 50;
if (i < n-1) printf("%d, ", array[i]);
else printf("%d\n", array[i]);
}
quickSort(array, 0, n);
printf("\nThe sorted array:\n");
for(int i = 0; i < n; i++)
if (i < n-1) printf("%d, ", array[i]);
else printf("%d\n", array[i]);
return 0;
}
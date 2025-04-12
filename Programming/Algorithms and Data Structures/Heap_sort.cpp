#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// балансировка вершины и ее потомков
void Heap(int first, int last, int mass[])
{
    int k, k2, k21;
    int buf;
    if (first <= last/2) {
        k = first; k2 = 2 * first + 1; k21 = k2 + 1;
        if ((k2 <= last) && (mass[first] < mass[k2]))
            k = k2;
        if ((k21 <= last) && (mass[k] < mass[k21]))
            k = k21;
        if (k != first) {
            buf = mass[first]; mass[first] = mass[k]; mass[k] = buf;
            Heap(k, last, mass);
        }
    }
}
// построение сортирующего дерева (кучи)
void BuildSortTree(int mass[], int size) 
{
    for (int i = size - 1; i >= 0; i--)
        Heap(i, size - 1, mass);
}
// извлечение максимального элемента
void HeapSort(int mass[], int size) 
{
    int buf;
    BuildSortTree(mass, size);
    for (int i = size - 1; i > 0; i--) {
        buf = mass[0]; mass[0] = mass[i]; mass[i] = buf;
        Heap(0, i - 1, mass);
    }
}
int main(void)
{
    int n = 0;
    srand(time(NULL));
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    printf("\nThe generated array:\n");
    for(int i = 0; i < n; i++) {
        array[i] = rand() % 101 - 50;
        if (i < n-1) printf("%d, ", array[i]);
        else printf("%d\n", array[i]);
    }
    HeapSort(array, n);
    printf("\nThe sorted array:\n");
    for(int i = 0; i < n; i++)
    if (i < n - 1) printf("%d, ", array[i]);
    else printf("%d\n", array[i]);
    return 0;
}
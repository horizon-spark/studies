#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calls = -1;

void printArray(int* arr, int size)
{   
    for (int i = 0; i < size; i++) {
        if (i < size - 1) printf("%d, ", arr[i]);
        else printf("%d\n", arr[i]);
    }
    return;
}

int* generateArray(int size)
{
    int* res = (int*)malloc(size * sizeof(int));
    int num;
    for (int i = 0; i < size; i++) {
        num = rand() % 101 - 50;
        res[i] = num;
    }
    return res;
}

void mergeSort(int* arr, int size)
{
  calls++;
  if (size == 1)
    return;
  mergeSort(arr, size/2);
  mergeSort(&arr[size/2], size - size/2);

  // calls += 2;

  int liter = 0; /* left half iteraor */
  int riter = 0; /* right half iteraor */
  int* tmp = (int*)malloc(size * sizeof(int));

  for(int i = 0; i < size; i++){
    if(arr[liter] < arr[size/2 + riter])
      tmp[i] = arr[liter++];
    else
      tmp[i] = arr[size/2 + riter++];

    if (liter == size / 2){ /* ran out of left half */
      while(riter < size - size / 2)
        tmp[++i] = arr[size/2 + riter++];
      break;
    } else if (riter == size - size / 2){ /* ran out of right half */
      while(liter < size / 2)
        tmp[++i] = arr[liter++];
      break;
    }
  }

  for(int i = 0; i < size; i++)
    arr[i] = tmp[i];
}

int main()
{
    srand(time(0));
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* arr = generateArray(size);
    printf("The generated array:\n");
    printArray(arr, size);
    mergeSort(arr,size);
    printf("After sorting the array:\n");
    printArray(arr,size);
    printf("The number of recursive calls: %d", calls);
}
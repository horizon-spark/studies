#include <iostream>
#define MAX 10

void insertionSort(int arr[])
{
    int i, key, j;
    for (i = 1; i < MAX; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

float average(int arr[])
{
    int sum = 0;
    float aver = 0.0;
    for (int i = 0; i < MAX; i++) {
        sum += arr[i];
    }
    aver = sum * 1.0 / MAX;
    return aver;
}

float newAverage(int arr[], float currAver, int newElem)
{
    float aver = 0.0;
    insertionSort(arr);
    if (newElem > arr[0] && newElem < arr[MAX-1]) {
        if (newElem >= currAver) {
            aver = ((currAver * MAX) - arr[MAX-1] + newElem) * 1.0 / MAX;
            arr[MAX-1] = newElem;
        } else if (newElem < currAver) {
            aver = ((currAver * MAX) - arr[0] + newElem) * 1.0 / MAX;
            arr[0] = newElem;
        }
    } else {
        return currAver;
    }
    return aver;
}

void print(int arr[]) 
{
    for (int i=0;i<MAX;i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
    return;
}

int main()
{
    int arr[] = {-4,3,-20,-3,11,2,4,7,-2,15};
    float aver = 0;

    std::cout << "Before sort" << std::endl;
    aver = average(arr);
    std::cout << "Average: " << aver << std::endl;
    print(arr);

    std::cout << "After sort" << std::endl;

    insertionSort(arr);
    aver = average(arr);
    std::cout << "Average: " << aver << std::endl;
    print(arr);

    std::cout << "After 'inserting' 16" << std::endl;

    aver = newAverage(arr,aver,16);
    std::cout << "Average: " << aver << std::endl;
    print(arr);

    std::cout << "After inserting 8" << std::endl;

    aver = newAverage(arr,aver,8);
    std::cout << "Average: " << aver << std::endl;
    print(arr);

    std::cout << "After inserting -5" << std::endl;

    aver = newAverage(arr,aver,-5);
    std::cout << "Average: " << aver << std::endl;
    print(arr);
    

}
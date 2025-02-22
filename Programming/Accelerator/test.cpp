#include <iostream>
#define MAX 10
double average(int arr[])
{
    int sum = 0;
    double aver;
    for (int i = 0; i < MAX; i++) {
        sum += arr[i];
    }
    aver = (double)(sum / MAX);
    return aver;
}

int main() 
{
    int arr[] = {1,3,7};
    double aver = average(arr);
    std::cout << aver;
}

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
}

vector<int> generateArray(int size) 
{
    vector<int> res;
    int num;
    for (int i = 0; i < size; i++) {
        num = rand() % 101 - 50;
        res.push_back(num);
    }
    return res;
}

int partition(vector<int>& arr, int left, int right)
{
    int i = left - 1, j = right, v = arr[right], buf;
    for ( ; ; ) {
        while (arr[++i] < v);
        while (v < arr[--j])
            if (j == left) break;
        if (i >= j) break;
        buf = arr[i]; arr[i] = arr[j]; arr[j] = buf;
    } 
    buf = arr[i]; arr[i] = arr[right]; arr[right] = buf;
    return i; 
}

void quickSort(vector<int>& arr, int left, int right)
{
    if (right <= left) return;
    int i = partition(arr, left, right);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
    return;
}

int main()
{
    int n = 0;
    srand(time(0));
    cout << "Enter the array size: ";
    cin >> n;
    vector<int> array = generateArray(n);
    cout << "The generated array: " << endl;
    printArray(array);
    quickSort(array, 0, n);
    cout << "The sorted array:" << endl;
    printArray(array);
    return 0;
}
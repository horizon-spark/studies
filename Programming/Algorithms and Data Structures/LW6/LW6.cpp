#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Heap(int first, int last, vector<int>& arr)
{
    int k, k21, k22;
    int buf;
    if (first <= last / 2) {
        k = first; k21 = 2 * first + 1; k22 = k21 + 1;
        if ((k21 <= last) && (arr[first] < arr[k21]))
            k = k21;
        if ((k22 <= last) && (arr[k] < arr[k22]))
            k = k22;
        if (k != first) {
            buf = arr[first]; arr[first] = arr[k]; arr[k] = buf;
            Heap(k, last, arr);
        }
    }
}
void BuildSortTree(vector<int>& arr)
{
    for (int i = arr.size() - 1; i >= 0; i--)
        Heap(i, arr.size() - 1, arr);
}
void HeapSort(vector<int>& arr)
{
    int buf;
    BuildSortTree(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        buf = arr[0]; arr[0] = arr[i]; arr[i] = buf;
        Heap(0, i - 1, arr);
    }
}
void generateArray(vector<int>& arr) 
{
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 101 - 50;
    }
    return;
}
void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
}
int main()
{
    int n = 0;
    srand(time(0));
    cout << "Enter the array size: ";
    cin >> n;
    vector<int> array(n);
    cout << "The generated array: " << endl;
    generateArray(array);
    printArray(array);
    HeapSort(array);
    cout << "The sorted array: " << endl;
    printArray(array);
}
#include <iostream>
#include <vector>

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

void ShellSort(vector<int>& arr)
{
    int v = 0, h = 0;
    for (h = 1; h <= arr.size() / 9; h = 3 * h + 1);
    for (; h > 0; h /= 3) {
        for (int i = h; i < arr.size(); i++) {
            int j = i;
            v = arr[i];
            while (j >= h && v < arr[j - h]) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = v;
        }
    }
    return;
}

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;
    vector<int> array = generateArray(size);
    cout << "The generated array: " << endl;
    printArray(array);
    ShellSort(array);
    cout << "The sorted array: " << endl;
    printArray(array);
}
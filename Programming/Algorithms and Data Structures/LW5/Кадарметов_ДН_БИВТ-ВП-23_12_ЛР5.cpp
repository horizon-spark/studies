#include <iostream>
#include <vector>

using namespace std;

int switches = 0;

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

int stepIncrement(int step, int mode)
{
    switch(mode)
    {
        case 0:
            return 2 * step;
        case 1:
            return 2 * step + 1;
        default:
            return 3 * step + 1;
    }
}

string stepFormula(int mode)
{
    switch(mode)
    {
        case 0:
            return "2h";
        case 1:
            return "2h + 1";
        default:
            return "3h + 1";
    }
}

vector<int> ShellSort(vector<int> array, int mode)
{
    switches = 0;
    vector<int> arr = array;
    int stepDivisor = mode < 2 ? 2 : 3; 
    int v = 0, h = 0;
    for (h = 1; h <= arr.size() / 9; h = stepIncrement(h, mode));
    cout << "Starting the Shell Sort with step " << stepFormula(mode) << ':' << endl;
    for (; h > 0; h /= stepDivisor) {
        for (int i = h; i < arr.size(); i++) {
            int j = i;
            v = arr[i];
            while (j >= h && v < arr[j - h]) {
                arr[j] = arr[j - h];
                switches++;
                j -= h;
            }
            arr[j] = v;
        }
        cout << "After sorting with step h = " << h << ":" << endl;
        printArray(arr);
    }
    return arr;
}

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;
    vector<int> array = generateArray(size);
    cout << "The generated array: " << endl;
    printArray(array);
    cout << endl;
    vector<int> sorted = ShellSort(array, 0);
    cout << "After Shell sort (step 2h): " << endl;
    printArray(sorted);
    cout << "The number of switches required: " << switches << endl << endl;

    sorted = ShellSort(array, 1);
    cout << "After Shell sort (step 2h + 1): " << endl;
    printArray(sorted);
    cout << "The number of switches required: " << switches << endl << endl;

    sorted = ShellSort(array, 2);
    cout << "After Shell sort (step 3h + 1): " << endl;
    printArray(sorted);
    cout << "The number of switches required: " << switches << endl;
}
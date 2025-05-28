#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<float> readArray(string filename)
{
    vector<float> result;
    ifstream input(filename);
    if (input.is_open()) {
        float buf;
        while (input >> buf) {
            result.push_back(buf);
        }
    }
    input.close();
    return result;
}

void printArray(vector<float>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
    return;
}

int main()
{
    vector<float> arr = readArray("input.txt");
    sort(arr.begin(), arr.end());
    cout << "The sorted array: ";
    printArray(arr);
    cout << "Size: " << arr.size() << endl;
}
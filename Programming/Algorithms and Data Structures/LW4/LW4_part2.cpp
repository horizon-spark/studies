#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void printArr(vector<string>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return;
}

vector<string> readFile(string filename)
{
    vector<string> result;
    string line;
    ifstream input(filename);
    if (input.is_open()) {
        while (getline(input,line)) {
            result.push_back(line);
        }
    }
    input.close();
    return result;
}

vector<string> LSDSort(vector<string> arr)
{
    int k = arr[0].size();
    vector<string> res = arr;
    vector<queue<string>> lsdArray(128);
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < res.size(); i++) {
            lsdArray[(int)(res[i][k - j - 1])].push(res[i]);
        }
        res.clear();
        for (int i = 0; i < lsdArray.size(); i++) {
            while (!lsdArray[i].empty()) {
                res.push_back(lsdArray[i].front());
                lsdArray[i].pop();
            }
        }
        cout << "After sorting by position " << j << ':' << endl;
        printArr(res);
    }
    return res;
}

int main()
{
    vector<string> words = readFile("input.txt");
    cout << "Before sorting: " << endl;
    printArr(words);
    vector<string> res = LSDSort(words);
    cout << "After sorting: " << endl;
    printArr(res);
}
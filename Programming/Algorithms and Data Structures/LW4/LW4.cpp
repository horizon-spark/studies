#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

void printArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return;
}

int generatRandomInRange(pair<int,int> range) 
{
    return rand() % (range.second - range.first + 1) + range.first;
}

pair<int,int> getRangeByK(int k) 
{
    pair<int,int> res;
    res.first = pow(10,k - 1);
    res.second = pow(10,k) - 1;
    return res;
}

int getDigitInPositionJ(int num, int j) 
{
    for (int i = 0; i < j; i++) {
        num /= 10;
    }
    return num % 10;
}

vector<int> generateSequence(int n, int k)
{
    vector<int> res;
    pair<int,int> range = getRangeByK(k);
    for (int i = 0; i < n; i++) {
        res.push_back(generatRandomInRange(range));
    }
    return res;
}

vector<int> LSDSort(vector<int> arr, int k)
{
    vector<int> res = arr;
    vector<queue<int>> lsdArray(10);
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < res.size(); i++) {
            lsdArray[getDigitInPositionJ(res[i],j)].push(res[i]);
        }
        res.clear();
        for (int i = 0; i < lsdArray.size(); i++) {
            while(!lsdArray[i].empty()) {
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
    srand(time(0));
    vector<int> vec = generateSequence(10, 4);
    cout << "Generated sequence:" << endl;
    printArr(vec);
    vector<int> res = LSDSort(vec, 4);
    cout << "After sort:" << endl;
    printArr(res);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int left, int right)
{
    if (arr.size() == 1) return;
    mergeSort(arr, left, right / 2);
    mergeSort(arr, right / 2 + 1, right);

    int leftIter = 0;
    int rightIter = 0;
    vector<int> buf(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        if (arr[leftIter] < arr[arr.size() / 2 + rightIter])
            buf[i] = arr[leftIter++];
        else 
            buf[i] = arr[arr.size() / 2 + rightIter++];
        
        
    }
}
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cmath>
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

void printIntervals(vector<pair<float, float>>& intervals)
{
    for (int i = 0; i < intervals.size(); i++) {
        cout << '[' << intervals[i].first << ';' << intervals[i].second << ')';
        if (i < intervals.size() - 1) cout << ", ";
        else cout << endl;
    }
}

int main()
{
    vector<float> arr = readArray("input.txt");
    vector<pair<float, float>> intervals;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    float range = arr.back() - arr.front();
    int classesCount = floor(1.0 + 3.322 * log10(n));
    float step = round(range / classesCount * 10.0) / 10.0;
    pair<float, float> buf = make_pair(arr.front(), arr.front() + step);
    intervals.push_back(buf);
    for (int i = 1; i < classesCount; i++) {
        buf.first = buf.second;
        buf.second = buf.first + step;
        intervals.push_back(buf);
    }
    cout << "The sorted array: ";
    printArray(arr);
    cout << "Range: " << range << endl;
    cout << "Number of classes: " << classesCount << endl;
    cout << "Step: " << step << endl;
    cout << "The calculated intervals: ";
    printIntervals(intervals);
}
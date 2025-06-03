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

void printIntervals(vector<pair<float, float>>& intervals, vector<int>& intervalSum)
{
    for (int i = 0; i < intervals.size(); i++) {
        cout << '[' << intervals[i].first << ';' << intervals[i].second << ") : " << intervalSum[i];
        if (i < intervals.size() - 1) cout << ", ";
        else cout << endl;
    }
}
void printMiddleIntervals(vector<pair<float, int>>& intervals)
{
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i].first << " : " << intervals[i].second;
        if (i < intervals.size() - 1) cout << ", ";
        else cout << endl;
    }
}

float average(vector<pair<float, int>>& intervals)
{
    float num = 0, denom = 0;
    for (int i = 0; i < intervals.size(); i++) {
        num += intervals[i].first * (float)intervals[i].second;
        denom += intervals[i].second;
    }
    return num / denom;
}

float squareAverage(vector<pair<float, int>>& intervals)
{
    float num = 0, denom = 0;
    for (int i = 0; i < intervals.size(); i++) {
        num += pow(intervals[i].first, 2) * (float)intervals[i].second;
        denom += intervals[i].second;
    }
    return num / denom;
}

int main()
{
    vector<float> arr = readArray("input.txt");
    vector<pair<float, float>> intervals;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    float range = arr.back() - arr.front();
    int classesCount = ceil(1.0 + 3.322 * log10(n));
    float step = ceil(range / classesCount * 100.0) / 100.0;
    pair<float, float> buf = make_pair(arr.front(), arr.front() + step);
    intervals.push_back(buf);
    for (int i = 1; i < classesCount; i++) {
        buf.first = buf.second;
        buf.second = buf.first + step;
        intervals.push_back(buf);
    }
    vector<int> elementIntervalCounter(classesCount, 0);
    for (int i = 0, j = 0; i < arr.size(); i++) {
        if (arr[i] >= intervals[j].second) {
            elementIntervalCounter[j + 1]++;
            j++;
            continue;
        }
        elementIntervalCounter[j]++;
    }
    vector<pair<float, int>> middleIntervals;
    pair<float, int> buf2;
    for (int i = 0; i < classesCount; i++) {
        buf2.first = round((intervals[i].first + intervals[i].second) * 100) / 200.0;
        buf2.second = elementIntervalCounter[i];
        middleIntervals.push_back(buf2);
    }
    cout << "The sorted array: ";
    printArray(arr);
    cout << "Range: " << range << endl;
    cout << "Number of classes: " << classesCount << endl;
    cout << "Step: " << step << endl;
    cout << "Intervals: ";
    printIntervals(intervals, elementIntervalCounter);
    cout << "Middle intervals: ";
    printMiddleIntervals(middleIntervals);
    cout << "Average: " << average(middleIntervals) << endl;
    cout << "Average of squares: " << squareAverage(middleIntervals) << endl;
}
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>

using namespace std;

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

vector<int> generateSequence(int n, int k)
{
    vector<int> res;
    pair<int,int> range = getRangeByK(k);
    for (int i = 0; i < n; i++) {
        res.push_back(generatRandomInRange(range));
    }
    return res;
}

int main()
{
    srand(time(0));
    vector<int> vec = generateSequence(10, 4);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}
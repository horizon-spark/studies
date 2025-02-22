#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int num;
    cout << "Insert a number of vertices" << endl;
    cin >> num;
    int vertex = 0;
    vector<pair<int,int>> edges;
    for (int i = 0; i < num; i++) {
        cin >> edges[i].first >> edges[i].second;
        int currMax = max(edges[i].first,edges[i].second);
        if (vertex < currMax) vertex = currMax;  
    }
}
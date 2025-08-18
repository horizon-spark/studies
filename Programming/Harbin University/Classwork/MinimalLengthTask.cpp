#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<int>& sortedCoords)
{
    int res = 0;
    for (int i = 0; i < 2; i++) {
        res += abs(sortedCoords[i] - sortedCoords[1]);
    }
    return res;
}

int main()
{
    vector<int> coords(3,0);
    int n, aver;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        coords.clear();
        cin >> coords[0] >> coords[1] >> coords[2];
        sort(coords.begin(), coords.end());
        cout << f(coords) << endl;
    }
    return 0;
}
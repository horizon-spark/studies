#include <iostream> 
#include <vector>

using namespace std;

int countMinDist(int x, int y, int k) 
{
    if (x > y) {
        return x;
    } else if (k >= (y - x)) {
        return y;
    } else {
        return 2 * y - x - k;
    }
    return 0;
}

int main()
{
    int t, x, y, k;
    vector<int> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> k;
        ans.push_back(countMinDist(x, y, k));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
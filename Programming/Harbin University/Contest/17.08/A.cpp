#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    vector<int> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v1(n,0), v2(n,0);
        int count = 1;
        for (int j = 0; j < n; j++) {
            cin >> v1[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> v2[j];
        }
        for (int j = 0; j < n; j++) {
            if (v1[j] > v2[j]) {
                count += v1[j] - v2[j];
            }
        }
        ans.push_back(count);
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
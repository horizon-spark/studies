#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, count = 1, ans = 1;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        count = 1;
        int x = arr[i];
        while(x != -1) {
            x = arr[x - 1];
            count++;
        }
        if (count > ans) ans = count;
    }
    cout << ans;
    return 0;
}
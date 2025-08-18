#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        vector<int> arr(n);
        int j = k-1, count = 1;
        while (j < n) {
            arr[j] = count;
            count++;
            j += (k-1);
        }
        for (j = 1; j < n; j++) {
            if (j % k != 0) {
                arr[j-1] = count;
                count++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
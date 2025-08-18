#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> x;
        vector<int> students(n,0);
        for (int i = 0; i < n; i++) {
            cin >> students[i];
        }
        sort(students.begin(), students.end(), greater<int>());
        if (students[0] < x) cout << 0 << endl;
        int sum = 0, ans = 0;
        for (int i = 0; i < students.size(); i++) {
            sum += 
        }
    }
    return 0;
}
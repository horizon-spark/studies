#include <iostream>
#include <vector>

using namespace std;

long long countSum(long long num)
{
    long long res = num;
    while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
            res += num;
        } else {
            num = (num - 1) / 2;
            res += num;
        }
    }
    return res;
}

int main()
{
    int t;
    long long num;
    vector<long long> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        ans.push_back(countSum(num));
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
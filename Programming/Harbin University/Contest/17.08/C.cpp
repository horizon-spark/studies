#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int t, num1, num2;
    string str;
    vector<pair<int, int>> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        pair<int, int> buf = make_pair(-1, -1);
        for (int j = (int)(str.size() / 2); j > 0; j--) {
            string s1 {str, j - 1}, s2 {str, j, str.size() - j};
            num1 = stoi(s1);
            num2 = stoi(s2);
            if (num2 > num1 && s1[0] != 0 && s2[0] != 0) {
                buf = make_pair(num1, num2);
                break;
            } 
        }
        ans.push_back(buf);
    }
    for (int i = 0; i < t; i++) {
        if (ans[i].first != -1) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
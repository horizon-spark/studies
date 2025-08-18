#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numberCount(int num)
{
    return num / 3;
}

int main()
{
    int t, num;
    vector<string> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        if (numberCount(num) % 2 != 0) {
            ans.push_back("Bob");
        } else {
            ans.push_back("Alice");
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void whoIsTheWinner(int num, vector<string>& ans)
{
    if ((num - 1) % 3 == 0 || (num + 1) % 3 == 0) {
        ans.push_back("First");
    } else {
        ans.push_back("Second");
    }
    return;
}

int main()
{
    int t, num;
    vector<string> ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        whoIsTheWinner(num, ans);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
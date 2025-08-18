#include <iostream>

using namespace std;

void isSquare(int l, int r, int d, int u)
{
    if (l == r && r == d && d == u) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    int t, l, r, d, u;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l >> r >> d >> u;
        isSquare(l, r, d, u);
    } 
    return 0;
}
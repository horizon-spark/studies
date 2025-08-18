#include <iostream>

using namespace std;

void isAliceTheWinner(int a, int b)
{
    if ((b - a) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main() 
{
    int n, a, b, buff;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> buff >> a >> b;
        isAliceTheWinner(a, b);
    }
}
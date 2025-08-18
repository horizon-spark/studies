#include <iostream>
#include <cmath>

using namespace std;

bool isReachable(int initX, int initY, int destX, int destY)
{
    return destY >= initY && (destY - initY >= destX - initX);
}

int minimalDistance(int initX, int initY, int destX, int destY)
{
    if (isReachable(initX, initY, destX, destY)) {
        return 2 * (destY - initY) + initX - destX;
    } 
    return -1;
}

int main() 
{
    int t, a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        cout << minimalDistance(a, b, c, d) << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void digitsSumIter(int num)
{
    int sum = 0;
    while (num != 0) {
        cout << num % 10;   
        sum += num % 10;
        num /= 10;
        if (num == 0) {
            cout << " = ";
        } else {
            cout << " + ";
        }
    }
    cout << sum << endl;
    return;
}

bool isFirstIter = true;
int digitsSumRecur(int num)
{
    int nextIterSum = 0;
    if (isFirstIter) {
        if (num == 0) return 0;
        isFirstIter = false;
        nextIterSum = digitsSumRecur(num / 10);
        cout << num % 10;
        return num % 10 + nextIterSum;
    }
    if (num == 0) 
        return 0;
    nextIterSum = digitsSumRecur(num / 10);
    cout << num % 10 << " + ";
    return num % 10 + nextIterSum;
}

int main()
{
    int number;
    cout << "Insert a number: ";
    cin >> number;
    cout << "Iterative solution: " << endl;
    digitsSumIter(abs(number));
    cout << "Recursive solution: " << endl;
    int res = digitsSumRecur(abs(number));
    cout << " = " << res << endl;
    return 0;
}

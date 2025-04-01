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
    if (isFirstIter) {
        if (num == 0) return 0;
        cout << num % 10;
        isFirstIter = false;
        return num % 10 + digitsSumRecur(num / 10);
    }
    if (num == 0) {
        cout << " = ";
        return 0;
    } 
    cout << " + " << num % 10;
    return num % 10 + digitsSumRecur(num / 10);
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
    cout << res << endl;
    return 0;
}
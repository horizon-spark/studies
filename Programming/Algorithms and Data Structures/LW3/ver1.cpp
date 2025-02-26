#include <iostream>
#include <cmath>

using namespace std;

int digitsSumIter(int num)
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
    return sum;
}
int main()
{
    int number;
    cout << "Insert a number: ";
    cin >> number;
    int res = digitsSumIter(abs(number));
    cout << res << endl;
    return 0;
}
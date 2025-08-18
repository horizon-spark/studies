#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int i = 0, j = 0, k = 0, count = 0;
    while(1) {
        while (str[i] != 'Q' && str.begin() + i != str.end()) {
            i++;
        }
        if (str.begin() + i == str.end()) break;
        i++;
        j = i;
        while (1) {
            while (str[j] != 'A' && str.begin() + j != str.end()) {
                j++;
            }
            if (str.begin() + j == str.end()) break;
            j++;
            k = j;
            while (1) {
                while (str[k] != 'Q' && str.begin() + k != str.end()) {
                    k++;
                }
                if (str.begin() + k == str.end()) break;
                count++;
                k++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
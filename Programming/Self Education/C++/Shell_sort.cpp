#include <iostream>

void ShellSort(int size, int *mass)
{
    int v = 0, h = 0;
    for (h = 1; h <= size / 9; h = 3 * h + 1);
    for (;h > 0; h /= 3) {
        for (int i = h; i < size; i++) {
            int j = i;
            v = *(mass + i);
            while (j >= h && v < *(mass + j - h)) {
                *(mass + j) = *(mass + j - h);
                j -= h;
            }
            *(mass + j) = v;
        }
    }
    return;
}
int main()
{
    int arr[] = {5, 17, 11, 25, 0, 3, 10, 20, 4, 8};
    ShellSort(10, arr);
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
}
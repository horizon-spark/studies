#include <iostream>
#include <vector>

int binary_search(std::vector<int> list, int item)
{
    int low = 0, mid = 0;
    int high = list.size()-1;
    int guess = 0;

    while (low <= high) {
        mid = (low + high)/2;
        guess = list[mid];
        if (guess == item) {
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    std::vector<int> my_vec_1{1,3,5,7,9};
    std::cout << binary_search(my_vec_1,3) << std::endl;
    std::cout << binary_search(my_vec_1,-1) << std::endl;
}
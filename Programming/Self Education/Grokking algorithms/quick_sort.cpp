#include <iostream>
#include <vector>

std::vector<int> quick_sort(std::vector<int> array)
{
    if (array.size() < 2) {
        return array;
    } else {
        int pivot = array[0];
        std::vector<int> less;
        std::vector<int> greater;
        for (int i=1;i<array.size();i++) {
            if (array[i]<pivot)
                less.push_back(array[i]);
            else 
                greater.push_back(array[i]);
        }
        less = quick_sort(less);
        greater = quick_sort(greater);
        less.insert(less.end(),pivot);
        less.insert(less.end(),greater.begin(),greater.end());
        return less;
    }
}

void print(std::vector<int> array)
{
    for (int i=0;i<array.size();i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> array{10,5,2,3};
    std::vector<int> sorted = quick_sort(array);
    std::cout << "Before sort: " << std::endl;
    print(array);
    std::cout << "After sort: " << std::endl;
    print(sorted);
}
#include <iostream>
#include <vector>

int findSmallest(std::vector<int> arr)
{
    int smallest = arr[0];
    int smallest_index = 0;
    for (int i=1;i<arr.size();i++) {
        if (arr[i]<smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

std::vector<int> selection_sort(std::vector<int> arr)
{
    std::vector<int> new_arr;
    int smallest = 0;
    int initial_size = arr.size();
    for (int i=0;i<initial_size;i++) {
        smallest = findSmallest(arr);
        new_arr.push_back(arr[smallest]);
        arr.erase(arr.begin()+smallest);
    }
    return new_arr;
}

int main()
{
    std::vector<int> array{5,3,6,2,10};
    std::vector<int> sorted = selection_sort(array);
    std::cout << "Before sort: " << std::endl;
    for (int i=0;i<array.size();i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Afted sort: " << std::endl;
    for (int i=0;i<sorted.size();i++) {
        std::cout << sorted[i] << "\t";
    }
}
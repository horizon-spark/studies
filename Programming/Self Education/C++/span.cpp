#include <iostream>
#include <vector>
#include <span>

double average(std::span<double>);

int main()
{
    std::vector<double> MyVec {1,2,3,4,5,6};
    double arr[] = {1,2,3,4,5,6};
    std::cout << "Average of the vector: " << average(MyVec) << std::endl;
    std::cout << "Average of the array: " << average(arr) << std::endl;
    return 0;
}

double average(std::span<double> data)
{
    double sum=0;
    for (unsigned i=0;i<data.size();i++)
    {
        sum += data[i];
    }
    return sum/data.size();
}

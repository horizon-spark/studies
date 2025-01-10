#include <iostream>

int mult (int a, int b)
{
    return a * b;
}

double mult(double a, double b)
{
    return a * b;
}

int main()
{
    std::cout << mult(5,2) << std::endl;
    std::cout << mult(5.1,2.2) << std::endl;
}
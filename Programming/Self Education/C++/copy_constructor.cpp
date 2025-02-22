#include <iostream>

class Integer
{
public:
    Integer(int number)
    {
        value=number;
    }
    Integer(const Integer &p)
    {
        value = p.value + 1;
    }
    void print() const
    {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main()
{
    Integer num_1{5};
    Integer num_2{num_1};
    num_2.print();
    return 0;
}
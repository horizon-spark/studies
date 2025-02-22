#include <iostream>
 
class Integer
{
public:
    Integer(int number)
    {
        value=number;
    }
    void print() const
    {
        std::cout << "Value: " << value << std::endl;
    }
    friend int compare(Integer &integer_1, Integer &integer_2);
private:
    int value;
};

int compare(Integer &integer_1, Integer &integer_2)
{
    if (integer_1.value > integer_2.value)
    {
        return 1;
    }
    else if (integer_1.value < integer_2.value)
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    Integer num_1 = {5};
    Integer num_2 = {5};
    std::cout << "Comparison result: " << compare(num_1,num_2) << std::endl;

}

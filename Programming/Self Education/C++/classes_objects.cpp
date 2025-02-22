#include <iostream>

class Integer
{
private:
    int x;
public:
    Integer(int p_x);
    void set_value(int i_x);
    int get_value();
    void print_value();
};

int main()
{
    Integer num{5};
    num.set_value(7);
    int x = num.get_value();
    num.print_value();
    std::cout << "The value of x: " << x << std::endl;
}

Integer::Integer(int p_x)
{
    x = p_x;
    std::cout << "Number was created" << std::endl;
}

void Integer::set_value(int i_x)
{
    x = i_x;
}

int Integer::get_value()
{
    return x;
}

void Integer::print_value()
{
    std::cout << "The value of Integer is: " << x << std::endl;
}
#include <iostream>
 
class Integer
{
public:
    Integer(int number);
    int getValue() const;
    void setValue(int number);
    void print() const;
private:
    int value;
};
Integer::Integer(int number)
{
    value=number;
    std::cout << "Object created" << std::endl;
}
int Integer::getValue() const { return value; }
void Integer::setValue(int number) { value = number; }
void Integer::print() const
{
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    int n,c_n;
    Integer num {5};
    const Integer const_num {7};

    n = num.getValue();
    std::cout << "Value of variable: " << n << std::endl;
    num.setValue(-5);
    num.print();

    c_n = const_num.getValue();
    std::cout << "Value of constant: " << c_n << std::endl;
    // const_num.setValue(-5);
    const_num.print();    
}

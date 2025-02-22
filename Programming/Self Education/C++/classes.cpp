#include <iostream>

class Person
{
public:
    std::string name;
    int age;
    void print()
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
    Person(std::string p_name, int p_age)
    {
        name = p_name;
        age = p_age;
        std::cout << "Person has been created" << std::endl;
    }
};

int main()
{
    Person tom("Tom",23);
    Person *p_tom = &tom;
    std::cout << "Name: " << p_tom->name << "\tAge: " << p_tom->age << std::endl;
    tom.print();
    return 0;
}
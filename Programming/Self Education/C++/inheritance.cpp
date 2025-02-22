#include <iostream>

class Animal
{
public:
    Animal(std::string name, unsigned int weight)
    {
        this->name = name;
        this->weight = weight;
    }
    void print()
    {
        std::cout << "Animal's name " << name << "\t Animal's weight " << weight << std::endl; 
    }
private:
    std::string name;
    unsigned int weight;
};

class Cat : public Animal 
{
public:
    Cat(std::string name, unsigned int weight) : Animal(name,weight) {}
};

class Dog : public Animal
{
public:
    Dog(std::string name, unsigned int weight) : Animal(name,weight) {}
};

int main()
{
    Cat alice {"Alice", 7};
    Cat mewo {"Mewo", 5};
    Dog ray {"Ray", 14};
    Dog jack {"Jack",12};

    alice.print();
    mewo.print();
    ray.print();
    jack.print();

    return 0;
}
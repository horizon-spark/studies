#include <iostream>

class Animal 
{
public:
    Animal(std::string name, unsigned weight) : name(name), weight(weight) {}
    void print()
    {
        std::cout << "Animal's name: " << name << "\t Weight: " << weight << std::endl;
    }
    virtual void make_sound() const = 0;
private:
    std::string name;
    unsigned weight;
};

class Dog : public Animal
{
public:
    Dog(std::string name, unsigned weight) : Animal(name,weight) {}
    void make_sound() const override 
    {
        std::cout << "Woof" << std::endl;
    }
private:
    std::string name;
    unsigned weight;
};

class Cat : public Animal
{
public:
    Cat(std::string name, unsigned weight) : Animal(name,weight) {}
    void make_sound() const override
    {
        std::cout << "Mew" << std::endl;
    }
private:
    std::string name;
    unsigned weight;
};

int main()
{
    Cat alice{"Alice",7};
    alice.print();
    alice.make_sound();
    Dog ray{"Ray",14};
    ray.print();
    ray.make_sound();
    return 0;
}
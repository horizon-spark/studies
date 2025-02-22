#include <stdio.h>

struct person
{
    char *name;
    int age;
};

void print(struct person);

int main()
{
    struct person Sam = {.name = "Sam",.age = 42};
    // person *p_person = &Sam;
    print(Sam);
    
}

void print(struct person user)
{
    printf("Name: %s\nAge: %d",user.name,user.age);
} 
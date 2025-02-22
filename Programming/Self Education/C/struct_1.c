#include <stdio.h>

// struct employee 
// {
//     char *name;
//     int age;
//     double salary;
// };

// int main()
// {
//     struct employee sam = {"Sam",23,4500.00};
//     printf("Name: %s \nAge: %d \nSalary: %.2lf",sam.name,sam.age,sam.salary);
//     return 0;
// }

typedef struct 
{
    char *name;
    int age;
    double salary;
} employee;

int main()
{
    employee sam = {"Sam",23,4500.00};
    printf("Name: %s \nAge: %d \nSalary: %.2lf",sam.name,sam.age,sam.salary);
    return 0;
}
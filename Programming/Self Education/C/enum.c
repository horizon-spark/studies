#include <stdio.h> 

enum color 
{
    Red,
    Green,
    Blue
};

void print(enum color col)
{
    switch(col)
    {
        case Red:
            printf("Red");
            break;
        case Green:
            printf("Green");
            break;
        case Blue:
            printf("Blue");
            break;
    }
}

int main()
{
    enum color col;
    col=1;
    print(col);
}


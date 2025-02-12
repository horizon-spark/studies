#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct stack_element 
{
    char data;
    struct stack_element *next;
} stack;
struct stack_element *top = NULL;

void push(char symb)
{
    struct stack_element *p = (struct stack_element*)malloc(sizeof(struct stack_element));
    p->next = top;
    p->data = symb;
    top = p;
}
char pop(void)
{
    if(top == NULL) {
        printf("Stack is empty\n");
        return '0';
    }
    char symb = top->data;
    struct stack_element *p = top;
    top = top->next;
    free(p);
    return symb;
}

int main()
{
    string str = "a+[b-v{m]}";
    for (int i=0;i<str.size();i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            push(str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            char buff = pop();
            if (buff == '0') {
                cout << "The number of closing bracket is more than opening ones";
                return -1;
            }
            if ((buff - str[i]) > 2) {
               cout << "Incorrect order of brackets" << endl;
               return 2; 
            }
        }
    }
    if (pop() != '0') {
        cout << "The number of opening brackets is more than closing ones";
        return 1;
    }
    cout << "The string is correct!";
    return 0;
}

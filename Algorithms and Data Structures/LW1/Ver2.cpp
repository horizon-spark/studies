#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{   
    private:
        char data;
        Stack *next;
    public:
        Stack *top;
        Stack()
        {
            top = NULL;
        }
        void push(char symb)
        {
            Stack *p = new class Stack;
            p->next = top;
            p->data = symb;
            top = p;
        }
        char pop(void)
        {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return '0';
            }
            char symb = top->data;
            Stack *p = top;
            top = top->next;
            delete(p);
            return symb;
        }
};

int main()
{
    Stack stack;
    string str;
    cout << "Input a string to check" << endl;
    cin >> str;
    for (int i=0;i<str.size();i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            stack.push(str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if (stack.top == NULL) {
                cout << "The number of closing bracket is more than opening ones";
                return -1;
            }
            char buff = stack.pop();
            if ((buff - str[i]) > 2) {
               cout << "Incorrect order of brackets on position " << i+1 << endl;
               return 2; 
            }
        }
    }
    if (stack.top != NULL) {
        cout << "The number of opening brackets is more than closing ones";
        return 1;
    }
    cout << "The string is correct!";
    return 0;
}

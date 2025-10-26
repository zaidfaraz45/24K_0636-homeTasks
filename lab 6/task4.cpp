#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class Stack 
{
    int topIndex;
    int size;
    char *arr;

public:
    Stack(int s) 
    {
        size = s;
        arr = new char[size];
        topIndex = -1;
    }

    ~Stack() 
    {
        delete[] arr;
    }

    bool isEmpty() 
    {
        return topIndex == -1;
    }

    bool isFull() 
    {
        return topIndex == size - 1;
    }

    void push(char val) 
    {
        if (!isFull()) {arr[++topIndex] = val;}
    }

    char pop() 
    {
        if (!isEmpty()) {return arr[topIndex--];}
        return '\0';
    }

    char peek() 
    {
        if (!isEmpty()) {return arr[topIndex];}
        return '\0';
    }
};

int precedence(char c) 
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string infix) 
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++) 
    {
        char c = infix[i];

        if (isalnum(c)) 
        {
            postfix += c;
        } 
        else if (c == '(') 
        {
            s.push(c);
        } 
        else if (c == ')') 
        {
            while (!s.isEmpty() && s.peek() != '(') 
            {
                postfix += s.pop();
            }
            if (!s.isEmpty()) s.pop(); 
        } 
        else
        {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) 
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) 
    {
        postfix += s.pop();
    }

    return postfix;
}

int main() 
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix Expression:   " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

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
        if (!isFull()) 
        {
            arr[++topIndex] = val;
        } 
        else 
        {
            cout << "Stack Overflow\n";
        }
    }

    char pop() 
    {
        if (!isEmpty()) 
        {
            return arr[topIndex--];
        } 
        else 
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
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

        if (isdigit(c)) 
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

int evaluatePostfix(string postfix) 
{
    int stack[postfix.length()];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) 
    {
        char c = postfix[i];

        if (isdigit(c)) 
        {
            stack[++top] = c - '0';
        } 
        else 
        {
            int val2 = stack[top--];
            int val1 = stack[top--];

            switch (c) 
            {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
                case '^': stack[++top] = pow(val1, val2); break;
            }
        }
    }

    return stack[top];
}

int main() 
{
    string infix = "2*3+(5*4)-9";
    cout << "Infix Expression: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

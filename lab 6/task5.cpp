#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack 
{
        int *arr;
        int topIndex;
        int size;

    public:
        Stack(int s) 
        {
            size = s;
            arr = new int[size];
            topIndex = -1;
        }

        ~Stack() 
        {
            delete[] arr;
        }

        void push(int val) 
        {
            if (topIndex < size - 1) 
            {
                arr[++topIndex] = val;
            } else 
            {
                cout << "Stack Overflow!" << endl;
            }
        }

        int pop() 
        {
            if (topIndex >= 0) 
            {
                return arr[topIndex--];
            } else 
            {
                cout << "Stack Underflow!" << endl;
                return 0;
            }
        }

        int top() 
        {
            if (topIndex >= 0)
                return arr[topIndex];
            return -1;
        }

        bool empty() 
        {
            return topIndex == -1;
        }
};

int evaluatePrefix(string prefix) 
{
    Stack s(prefix.length());

    for (int i = prefix.length() - 1; i >= 0; i--) 
    {
        char c = prefix[i];

        if (isdigit(c)) 
        {
            s.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        {
            int op1 = s.pop();
            int op2 = s.pop();
            int result;

            switch (c) 
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main() 
{
    string prefix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    int result = evaluatePrefix(prefix);

    cout << "Result: " << result << endl;

    return 0;
}

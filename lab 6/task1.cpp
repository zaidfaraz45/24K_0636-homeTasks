#include <iostream>
using namespace std;

class CallHistory
{
    string *name;
    long long *number;
    int *duration;

    int i;
    int size;

public:
    CallHistory(int s = 10)
    {
        size = s;
        i = 0;

        name = new string[size];
        number = new long long[size];
        duration = new int[size];
    }

    ~CallHistory()
    {
        delete[] name;
        delete[] number;
        delete[] duration;
    }

    void display()
    {
        if (i == 0)
        {
            cout << "No call history.\n";
            return;
        }

        cout << "------Call History------\n";
        for (int x = 0; x < i; x++)
        {
            cout << "Record " << x + 1 << ":\n";
            cout << "  Name: " << name[x] << "\n";
            cout << "  Number: " << number[x] << "\n";
            cout << "  Duration: " << duration[x] << " minutes\n";
        }
    }

    void push(string n, long long num, int d)
    {
        if (i < size)
        {
            name[i] = n;
            number[i] = num;
            duration[i] = d;
            i++;

            cout << "Call record pushed!\n";
            display();
        }
        else
        {
            cout << "Call history is full!\n";
        }
    }

    bool empty()
    {
        return i == 0;
    }

    void pop()
    {
        if (!empty())
        {
            i--;
            cout << "Last call record popped!\n";
        }
        else
        {
            cout << "Call history is empty!\n";
        }

        display();
    }

    void top()
    {
        if (!empty())
        {
            cout << "------Last Call------\n";
            cout << "Name: " << name[i - 1] << "\n";
            cout << "Number: " << number[i - 1] << "\n";
            cout << "Duration: " << duration[i - 1] << " minutes\n";
        }
        else
        {
            cout << "No calls in history!\n";
        }
    }
};

int main()
{
    CallHistory ch;
    
    ch.push("Ali Khan", 923001234567, 12);
    ch.push("Sara Ahmed", 923009876543, 8);
    ch.top();
    ch.pop();

    return 0;
}

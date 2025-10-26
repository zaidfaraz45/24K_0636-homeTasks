#include <iostream>
using namespace std;

class Library
{
    int front;
    int rear;
    int size;
    string *patrons;

public:
    Library(int s) : front(0), rear(0), size(s)
    {
        patrons = new string[s];
    }

    ~Library()
    {
        delete[] patrons;
    }

    bool empty()
    {
        return (front == rear);
    }

    bool full()
    {
        return (rear == size);
    }

    void enqueue(string name)
    {
        if (full())
        {
            cout << "Queue is full!\n";
            return;
        }

        patrons[rear] = name;
        rear++;

        cout << name << " is enqueued!\n";
        display();
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue empty!\n";
            return;
        }

        cout << patrons[front] << " is dequeued!\n";
        front++;

        display();
    }

    void display()
    {
        cout << "--------QUEUE--------\n";
        for (int i = front; i < rear; i++)
        {
            cout << (i - front + 1) << ". " << patrons[i] << endl;
        }
        cout << endl;
    }
};

int main()
{
    Library libQueue(5); 

    libQueue.enqueue("Ali");
    libQueue.enqueue("Sara");
    libQueue.enqueue("John");
    libQueue.enqueue("Fatima");
    libQueue.enqueue("Usman");

    libQueue.enqueue("Zara");

    libQueue.dequeue();
    libQueue.dequeue();

    libQueue.enqueue("Zara");
    libQueue.enqueue("Adeel");

    libQueue.dequeue();

    return 0;
}

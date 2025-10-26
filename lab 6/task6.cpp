#include <iostream>
using namespace std;

class Orders
{
    int front;
    int rear;
    int size;
    string *order;
    int count;

    public:
        Orders(int s): front(0), rear(0), size(s), count(0) 
        {
            order = new string[s];
        }

        ~Orders()
        {
            delete[] order;
        }

        bool empty()
        {
            return (count == 0);
        }

        bool full()
        {
            return (count == size);
        }

        void enqueue(string ord)
        {
            if (full())
            {
                cout << "The queue is full!\n";
                return;
            }

            order[rear] = ord;
            rear = (rear + 1) % size;
            count++;

            cout << ord << " is enqueued!\n";
            display();
        }

        void dequeue()
        {   
            if (empty())
            {
                cout << "The queue is empty!\n";
                return;
            }

            cout << order[front] << " is dequeued!\n";
            front = (front + 1) % size;
            count--;

            display();
        }

        void display()
        {
            cout << "--------ORDERS--------\n";
            for (int i = 0; i < count; i++)
            {
                int x = (front + i) % size;
                cout << i + 1 << ". " << order[x] << endl;
            }
            cout << endl;
        }
};

int main()
{
    Orders order(10);
    order.enqueue("Burger");
    order.enqueue("Pizza");
    order.enqueue("Biryani");
    order.enqueue("Kabab");
    order.enqueue("Fries");
    order.enqueue("Shawarma");
    order.enqueue("Pasta");
    order.enqueue("Steak");
    order.enqueue("Sandwich");
    order.enqueue("Coffee"); 
    order.enqueue("Ice Cream");

    order.dequeue();
    order.dequeue();
    order.dequeue();

    order.enqueue("Donut");
    order.enqueue("Taco");

    return 0;
}

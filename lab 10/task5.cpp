#include <iostream>
using namespace std;

struct Node
{
    int value;
    int priority;
    Node *next;

    Node(int val, int p): value(val), priority(p) {}
};

class PriorityQueue
{
    Node *front;

    public:
        PriorityQueue() : front(nullptr) {}

        ~PriorityQueue() 
        {
            while (front) 
            {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void insert(int val, int p) 
        {
            Node* newNode = new Node(val, p);

            if (!front || p > front->priority) 
            {
                newNode->next = front;
                front = newNode;
            } 
            else 
            {
                Node* current = front;
                while (current->next && current->next->priority >= p) 
                {
                    current = current->next;
                }

                newNode->next = current->next;
                current->next = newNode;
            }
        }

        void remove() 
        {
            if (!front) 
            {
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* temp = front;
            front = front->next;
            delete temp;
            }

        void display() 
        {
            if (!front) 
            {
                cout << "Queue is empty!" << endl;
                return;
            }

            Node* current = front;
            while (current) 
            {
                cout << "(" << current->value << ", " << current->priority << ") ";
                current = current->next;
            }
            cout << endl;
        }
};

int main()
{
    PriorityQueue matchmaking;

    matchmaking.insert(1500, 1500);
    matchmaking.insert(1200, 1200);
    matchmaking.insert(1800, 1800);
    matchmaking.insert(1600, 1600);
    matchmaking.display();

    matchmaking.insert(1700, 1700);
    matchmaking.display();

    matchmaking.remove();
    matchmaking.display();

    return 0;
}

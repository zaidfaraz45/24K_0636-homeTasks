#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

    public:
        
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        
};

int main()
{
    return 0;
}
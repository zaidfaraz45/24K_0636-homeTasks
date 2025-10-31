#include <iostream>
using namespace std;

struct StudentRecord
{
    string name;
    int score;
};

struct Node
{
    StudentRecord record;
    Node *next;

    Node(string name, int score): record{name, score}, next(nullptr) {}
};

class LinkedList
{
    Node *head;
    Node *tail;

    public:
        void insertAtHead(string n, int s)
        {
            if (head == nullptr)
            {
                
            }
        }
};

int main()
{
    
    return 0;
}

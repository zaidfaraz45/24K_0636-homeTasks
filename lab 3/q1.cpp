#include <iostream>
using namespace std;

struct Node 
{
    string data;
    Node* next;

    Node(string val) 
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList 
{
    Node* head;
    Node* tail;

public:
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(string val) 
    {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;

        if (tail == nullptr) 
        {
            tail = head;
        }
    }

    void insertAtTail(string val) 
    {
        Node* temp = new Node(val);

        if (head == nullptr) 
        {
            head = temp;
            tail = temp;
        }
        else 
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAfter(string val, string valIns) 
    {
        Node* prev = head;

        while (prev != nullptr && prev->data != val) 
        {
            prev = prev->next;
        }

        if (prev == nullptr) 
        {
            cout << "Value " << val << " not found!\n";
            return;
        }

        Node* temp = new Node(valIns);
        temp->next = prev->next;
        prev->next = temp;

        if (prev == tail) 
        {
            tail = temp;
        }
    }

    void search(string val) 
    {
        Node* temp = head;

        while (temp != nullptr) 
        {
            string item = temp->data.substr(0, temp->data.find('-'));

            if (item == val) 
            {
                cout << "Item found! " << temp->data << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Item not found!\n";
    }

    void display() 
    {
        Node* temp = head;

        while (temp != nullptr) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() 
{
    LinkedList cart;

    cart.insertAtHead("Laptop-$1000");
    cart.insertAtTail("Phone-$700");
    cart.insertAtTail("Tablet-$400");
    cart.insertAtTail("Headphones-$150");

    cart.insertAtHead("Smartwatch-$200");
    cart.insertAtTail("Keyboard-$80");
    cart.insertAfter("Phone-$700", "Monitor-$300");

    cart.search("Tablet");

    cart.display();

    return 0;
}

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

    void deleteFromFront()
    {
        if (head == NULL) {return;}

        Node *next = head->next;
        delete head;
        head = next;

        if (head == NULL) {tail = NULL;}
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

    void searchPosition(int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position entered!\n";
            return;
        }

        Node *temp = head;
        int i = 1;

        while (i != pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            cout << "Invalid position entered!\n";
            return;
        }

        cout << "Item " << temp->data << " at position " << pos << endl;
    }

    void searchItem(string item)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == item)
            {
                cout << item << " Item found!\n";
                return;
            }

            temp = temp->next;
        }

        cout << item << "Item not avaialable!" << endl;
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
    cart.display();

    cart.deleteFromFront();
    cart.searchItem("Tablet-$400");
    cart.searchPosition(2);

    cart.display();

    return 0;
}

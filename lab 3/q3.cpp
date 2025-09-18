#include <iostream>
using namespace std;

struct Node
{
    int id;
    string name;
    double price;
    Node* next;
    Node* prev;

    Node(int i, string n, double p)
    {
        id = i;
        name = n;
        price = p;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList
{
    Node* head;
    Node* tail;

    public:
        DoublyList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void insertAtEnd(int id, string name, double price)
        {
            Node* temp = new Node(id, name, price);
            if (head == nullptr)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }

        void insertAtFront(int id, string name, double price)
        {
            Node* temp = new Node(id, name, price);
            if (head == nullptr)
            {
                head = tail = temp;
            }
            else
            {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void deleteFirstItem()
        {
            if (head == nullptr) return;

            Node* toDelete = head;
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;

            delete toDelete;
        }

        void deleteLastItem()
        {
            if (tail == nullptr) return;

            Node* toDelete = tail;
            tail = tail->prev;

            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;

            delete toDelete;
        }

        void searchID(int id)
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                if (temp->id == id)
                {
                    cout << "Item Found -> ID: " << temp->id
                        << ", Name: " << temp->name
                        << ", Price: $" << temp->price << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Item with ID " << id << " not found.\n";
        }

        void updatePrice(int id, double newPrice)
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                if (temp->id == id)
                {
                    temp->price = newPrice;
                    cout << "Price updated for item " << temp->name
                        << " -> New Price: $" << newPrice << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Item with ID " << id << " not found.\n";
        }

        void displayForward()
        {
            Node* temp = head;
            cout << "Cart (Front -> End): ";
            while (temp != nullptr)
            {
                cout << "[" << temp->id << ", " << temp->name << ", $" << temp->price << "] <-> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }

        void displayBackward()
        {
            Node* temp = tail;
            cout << "Cart (End -> Front): ";
            while (temp != nullptr)
            {
                cout << "[" << temp->id << ", " << temp->name << ", $" << temp->price << "] <-> ";
                temp = temp->prev;
            }
            cout << "NULL\n";
        }

        int numberOfItems()
        {
            int count = 0;
            Node* temp = head;
            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }

        void mostExpensiveItem()
        {
            if (head == nullptr)
            {
                cout << "Cart is empty.\n";
                return;
            }

            Node* temp = head;
            Node* expensive = head;

            while (temp != nullptr)
            {
                if (temp->price > expensive->price)
                    expensive = temp;
                temp = temp->next;
            }

            cout << "Most Expensive Item -> ID: " << expensive->id
                << ", Name: " << expensive->name
                << ", Price: $" << expensive->price << endl;
        }
};

int main()
{
    DoublyList cart;

    cart.insertAtEnd(101, "Laptop", 1200);
    cart.insertAtEnd(102, "Phone", 800);
    cart.insertAtFront(100, "Tablet", 50);
    cart.insertAtEnd(103, "Headphones", 150);

    cart.displayForward();
    cart.displayBackward();

    cart.searchID(102);
    cart.updatePrice(103, 180);

    cout << "Total items in cart: " << cart.numberOfItems() << endl;

    cart.mostExpensiveItem();

    cart.deleteFirstItem();
    cart.deleteLastItem();

    cart.displayForward();

    return 0;
}

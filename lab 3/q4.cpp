#include <iostream>
using namespace std;

struct Node 
{
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cname, string rname) 
    {
        ticketID = id;
        customerName = cname;
        rideName = rname;
        next = nullptr;
    }
};

class CircularList 
{
    Node* head;
    Node* tail;

    public:
        CircularList() 
        {
            head = nullptr;
            tail = nullptr;
        }

        void issueAtEnd(int id, string cname, string rname) 
        {
            Node* temp = new Node(id, cname, rname);
            if (head == nullptr) 
            {
                head = tail = temp;
                tail->next = head; 
            }
            else 
            {
                tail->next = temp;
                tail = temp;
                tail->next = head;
            }
        }

        void issueAtFront(int id, string cname, string rname) 
        {
            Node* temp = new Node(id, cname, rname);
            if (head == nullptr) 
            {
                head = tail = temp;
                tail->next = head;
            }
            else 
            {
                temp->next = head;
                head = temp;
                tail->next = head; 
            }
        }

        void cancelByID(int id) 
        {
            if (head == nullptr) return;

            Node* curr = head;
            Node* prev = tail;
            do 
            {
                if (curr->ticketID == id) 
                {
                    if (curr == head) 
                    { 
                        cancelFirst();
                        return;
                    }
                    else 
                    {
                        prev->next = curr->next;
                        if (curr == tail) tail = prev; 
                        delete curr;
                        cout << "Ticket " << id << " cancelled!\n";
                        return;
                    }
                }

                prev = curr;
                curr = curr->next;
            } while (curr != head);

            cout << "Ticket ID " << id << " not found!\n";
        }

        void cancelFirst() 
        {
            if (head == nullptr) return;

            if (head == tail) 
            { 
                delete head;
                head = tail = nullptr;
            }
            else 
            {
                Node* toDelete = head;
                head = head->next;
                tail->next = head; 
                delete toDelete;
            }

            cout << "First ticket cancelled!\n";
        }

        void searchID(int id) 
        {
            if (head == nullptr) 
            {
                cout << "List empty!\n";
                return;
            }

            Node* temp = head;
            do 
            {
                if (temp->ticketID == id) 
                {
                    cout << "Ticket Found -> ID: " << temp->ticketID << ", Customer: " << temp->customerName << ", Ride: " << temp->rideName << endl;
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout << "Ticket ID " << id << " not found!\n";
        }

        void display() 
        {
            if (head == nullptr) 
            {
                cout << "No tickets booked!\n";
                return;
            }

            Node* temp = head;
            cout << "Tickets:\n";
            do 
            {
                cout << "[ID: " << temp->ticketID << ", " << temp->customerName << ", " << temp->rideName << "] -> ";
                temp = temp->next;
            } while (temp != head);
            cout << "(start)\n";
        }

        int totalTickets() 
        {
            if (head == nullptr) return 0;

            int count = 0;
            Node* temp = head;
            do 
            {
                count++;
                temp = temp->next;
            } while (temp != head);

            return count;
        }

        void nextAfter(int id) 
        {
            if (head == nullptr) 
            {
                cout << "List empty!\n";
                return;
            }

            Node* temp = head;
            do 
            {
                if (temp->ticketID == id) 
                {
                    Node* next = temp->next;
                    cout << "Next Ticket -> ID: " << next->ticketID
                        << ", Customer: " << next->customerName
                        << ", Ride: " << next->rideName << endl;
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout << "Ticket ID " << id << " not found!\n";
        }
};

int main() 
{
    CircularList booking;

    booking.issueAtEnd(1, "Alice", "Roller Coaster");
    booking.issueAtEnd(2, "Bob", "Ferris Wheel");
    booking.issueAtFront(0, "VIP-John", "Haunted House");
    booking.display();

    booking.searchID(2);
    booking.nextAfter(2);

    cout << "Total tickets: " << booking.totalTickets() << endl;

    booking.cancelByID(1);
    booking.cancelFirst();

    booking.display();

    return 0;
}

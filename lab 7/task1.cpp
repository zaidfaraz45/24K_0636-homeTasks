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
    Node(string name, int score) : record{name, score}, next(nullptr) {}
};

class LinkedList
{
    Node *head;
    Node *tail;

    int findMax()
    {
        int max = head->record.score;
        for (Node *temp = head; temp != nullptr; temp = temp->next)
        {
            if (temp->record.score > max) {max = temp->record.score;}
        }
        return max;
    }

    void countingSort(int exp)
    {
        Node *buckets[10] = {nullptr};     
        Node *bucketTails[10] = {nullptr}; 

        Node *curr = head;
        while (curr)
        {
            int index = (curr->record.score / exp) % 10;

            Node *nextNode = curr->next;
            curr->next = nullptr;

            if (!buckets[index])
            {
                buckets[index] = bucketTails[index] = curr;
            }
            else
            {
                bucketTails[index]->next = curr;
                bucketTails[index] = curr;
            }

            curr = nextNode;
        }

        head = tail = nullptr;
        for (int i = 0; i < 10; i++)
        {
            if (buckets[i])
            {
                if (!head)
                {
                    head = buckets[i];
                    tail = bucketTails[i];
                }
                
                else
                {
                    tail->next = buckets[i];
                    tail = bucketTails[i];
                }
            }
        }
    }


    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        void insertAtHead(string n, int s)
        {
            Node *temp = new Node(n, s);
            if (!head)
            {
                head = tail = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }

        void display()
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->record.name << " : " << temp->record.score << endl;
                temp = temp->next;
            }
        }

        void radixSort()
        {
            int maxScore = findMax();

            for (int exp = 1; maxScore / exp > 0; exp *= 10) {countingSort(exp);}
        }
};

int main()
{
    LinkedList students;
    students.insertAtHead("Ali", 56);
    students.insertAtHead("Sara", 89);
    students.insertAtHead("Ahmed", 23);
    students.insertAtHead("Zara", 99);
    students.insertAtHead("Bilal", 45);

    cout << "Before Sorting:\n";
    students.display();

    students.radixSort();

    cout << "\nAfter Sorting:\n";
    students.display();

    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    string URL;
    Node *next;

    Node(string val)
    {
        URL = val;
        next = nullptr;
    }
};

class WebsiteList
{
    Node *previous;
    Node *top;

    public:
        WebsiteList()
        {
            previous = nullptr;
            top = nullptr;
        }

        void push(string url)
        {
            Node *temp = new Node(url);

            temp->next = top;
            top = temp;

            cout << "Website pushed: " << url << endl;
            display();
        }

        void pop()
        {
            if (top == nullptr)
            {
                cout << "The list is empty!\n";
                return;
            }

            Node *temp = top;
            top = top->next;

            cout << "Website popped: " << temp->URL << "\n";
            delete temp;

            display();
        }

        void display() const
        {
            if (top == nullptr)
            {
                cout << "No websites visited yet!\n";
                return;
            }

            cout << "------ Website List ------\n";

            Node *temp = top;
            int count = 1;
            while (temp != nullptr)
            {
                cout << temp->URL << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }

};

int main()
{
    WebsiteList wl;
    wl.push("Google");
    wl.push("Facebook");
    wl.push("Twitter");
    wl.push("Linkedin");
    wl.push("Instagram");

    wl.pop();
    wl.pop();
    wl.pop();

    return 0;
}

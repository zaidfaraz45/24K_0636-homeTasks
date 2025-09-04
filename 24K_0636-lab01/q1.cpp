#include <iostream>
#include <string>
using namespace std;

class ResearchPaper 
{
        string* authors;   
        int count;         

    public:
        ResearchPaper() 
        {
            count = 0;
            authors = NULL;
        }

        ResearchPaper(string* auth, int n) 
        {
            count = n;

            authors = new string[count];
            for (int i = 0; i < count; i++) 
            {
                authors[i] = auth[i];
            }
        }

        ResearchPaper(const ResearchPaper& other) 
        {
            count = other.count;

            authors = new string[count];
            for (int i = 0; i < count; i++) 
            {
                authors[i] = other.authors[i];
            }
        }

        ResearchPaper& operator=(const ResearchPaper& other) 
        {
            if (this == &other) {return *this;}

            delete[] authors;

            count = other.count;
            authors = new string[count];
            for (int i = 0; i < count; i++) 
            {
                authors[i] = other.authors[i];
            }
            return *this;
        }

        ~ResearchPaper() 
        {
            delete[] authors;
        }

        void changeAuthor(int index, string newAuthor) 
        {
            if (index >= 0 && index < count) 
            {
                authors[index] = newAuthor;
            }
        }

        void displayAuthors() const 
        {
            cout << "Authors:\n";
            for (int i = 0; i < count; i++) 
            {
                cout << authors[i];
                cout << endl;
            }
        }
};

int main() 
{
    string authorNames1[] = {"Alice", "Bob", "Charlie"};
    ResearchPaper paper1(authorNames1, 3);

    cout << "Paper 1:" << endl;
    paper1.displayAuthors();

    ResearchPaper paper2 = paper1;
    cout << "Paper 2:" << endl;
    paper2.displayAuthors();

    paper2.changeAuthor(1, "David");

    cout << "\nPaper1:\n";
    paper1.displayAuthors();
    cout << "Paper2:\n";
    paper2.displayAuthors();

    return 0;
}

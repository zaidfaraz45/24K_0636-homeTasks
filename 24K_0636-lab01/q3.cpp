#include <iostream>
using namespace std;

class Exam
{
    int *marks;

    public:
        Exam()
        {
             marks = new int(0);
        }

        Exam(int m)
        {
            marks = new int(m);
        }

        void changeMarks(int m)
        {
            *marks = m;
        }

        void displayMarks() const
        {
            cout << *marks << endl;
        }

        ~Exam() 
        {
            delete marks;
        }
};


int main()
{
    Exam Maths(78);
    Exam Islamiyat = Maths;
    cout << "Maths marks: ";
    Maths.displayMarks();
    cout << "Islamiyat marks: ";
    Islamiyat.displayMarks();

    Islamiyat.changeMarks(85);
    cout << "Maths marks: ";
    Maths.displayMarks();
    cout << "Islamiyat marks: ";
    Islamiyat.displayMarks();

    return 0;
}
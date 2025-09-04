#include <iostream>
using namespace std;

class Box
{
    int *volume;

    public:
        Box()
        {
             volume = new int(0);
        }

        Box(int vol)
        {
            volume = new int(vol);
        }

        Box(const Box &other)
        {
            volume = new int(*other.volume);
        }

        void changeVol(int vol)
        {
            *volume = vol;
        }

        void displayVol() const
        {
            cout << *volume << endl;
        }

        ~Box() 
        {
            delete volume;
        }
};

int main()
{
    Box box1(1);
    Box box2 = box1;
    cout << "Volume of box 1: ";
    box1.displayVol();
    cout << "Volume of box 2: ";
    box2.displayVol();

    box2.changeVol(2);
    cout << "Volume of box 1: ";
    box1.displayVol();
    cout << "Volume of box 2: ";
    box2.displayVol();

    return 0;
}
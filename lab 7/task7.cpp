#include <iostream>
#include <vector>
using namespace std;

int findMax(vector <int> arr)
{
    int max = arr[0];
    int length = arr.size();

    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}



int main()
{
    int array[50];

    
    
    return 0;
}

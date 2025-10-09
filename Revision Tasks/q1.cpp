#include <iostream>
using namespace std;

//Shell sort is better int this case than insertion sort as the array is moderately sorted and shell sort moves slower values closer to the start early on. Therefore, the number of comparisons and swaps needed in the later passes is much smaller than what Insertion Sort would do.
void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }

            arr[res] = temp;
        }

        cout << "After gap = " << gap << " : [";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i != size - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}

void displayArr(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    int arr[] = {205, 102, 310, 450, 120, 90};
    int size = 6;

    cout << "Original array: ";
    displayArr(arr, size);

    shellSort(arr, size);

    cout << "\nSorted array: ";
    displayArr(arr, size);

    return 0;
}

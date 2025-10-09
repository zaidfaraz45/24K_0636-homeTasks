#include <iostream>
using namespace std;

// Shell Sort is preferred because it is faster than Bubble Sort for moderately sized arrays and nearly sorted data.If the luggage is nearly sorted, Shell Sort performs much faster because fewer movements are needed, often approaching linear time, unlike Bubble Sort which still does many comparisons.
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
    int arr[] = {32, 25, 40, 12, 18, 50, 28};
    int size = 7;

    cout << "Original array: ";
    displayArr(arr, size);

    shellSort(arr, size);

    cout << "\nSorted array: ";
    displayArr(arr, size);

    return 0;
}

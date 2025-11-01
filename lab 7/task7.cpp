#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Scores
{
    string student;
    int score;
};

int findMax(Scores arr[], int n)
{
    int max = arr[0].score;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].score > max)
        {
            max = arr[i].score;
        }
    }

    return max;
}

void countingSort(Scores arr[], int n, int exp) 
{
    Scores output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i].score / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        int index = (arr[i].score / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {arr[i] = output[i];}
}

void radixSort(Scores arr[], int n) 
{
    int m = findMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int n = 50;

    Scores scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i].score = rand() % 101;
        scores[i].student = "Student " + to_string(i + 1);

    }

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i].student << ": " << scores[i].score << endl;
    }

    radixSort(scores, 50);

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i].student << ": " << scores[i].score << endl;
    }
    
    return 0;
}

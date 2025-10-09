#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int x, int y)     // x is vertical and y is horizontal
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }

    return false;
}

bool maze(int **arr, int n, int x, int y, int **sol)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, n, x, y))
    {
        sol[x][y] = 1;

        if (maze(arr, n, x + 1, y, sol))
        {
            return true;
        }

        if (maze(arr, n, x, y + 1, sol))
        {
            return true;
        }

        sol[x][y] = 2;  //backtracked
        return false;   //If no safe route exists, this line of code is activated.
    }

    return false;
}

int main()
{
    int n = 5;
    int** array = new int*[n];   
    for (int i = 0; i < n; i++) 
    {
        array[i] = new int[n];   
    }

    int Array[5][5] = 
    {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            array[i][j] = Array[i][j];
        }
    }

    int **sol = new int*[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }

    if (maze(array, n, 0, 0, sol))
    {
        cout << "Solution path:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No path found!\n";     //If no safe route is there
    }

    for (int i = 0; i < n; i++)
    {
        delete[] array[i];
        delete[] sol[i];
    }
    delete[] array;
    delete[] sol;

    return 0;
}

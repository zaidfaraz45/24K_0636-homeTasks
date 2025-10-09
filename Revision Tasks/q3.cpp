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

bool warehouse(int **arr, int n, int x, int y, int **sol)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, n, x, y))
    {
        sol[x][y] = 1;

        if (warehouse(arr, n, x + 1, y, sol))
        {
            return true;
        }

        if (warehouse(arr, n, x, y + 1, sol))
        {
            return true;
        }

        sol[x][y] = 2;  //backtracked
        return false;
    }

    return false;
}

int main()
{
    int n = 4;
    int** array = new int*[n];   
    for (int i = 0; i < n; i++) 
    {
        array[i] = new int[n];   
    }

    int Array[4][4] = 
    {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
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

    if (warehouse(array, n, 0, 0, sol))
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
        cout << "No path found!\n";
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

//The algorithm always tries moving down first (x + 1), then right (y + 1). So if multiple paths exist, the robot will follow the downward path first, backtracking only if that path leads to a dead end.

#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int x, int y, int **sol)     // x is vertical and y is horizontal
{
    if (x < n && y < n && x >= 0 && y >= 0 && arr[x][y] == 1 && sol[x][y] == 0)
    {
        return true;
    }

    return false;
}

bool childInMaze(int **arr, int n, int x, int y, int **sol)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, n, x, y, sol))
    {
        sol[x][y] = 1;

        if (childInMaze(arr, n, x + 1, y, sol))
        {
            return true;
        }

        if (childInMaze(arr, n, x, y + 1, sol))
        {
            return true;
        }

        if (childInMaze(arr, n, x - 1, y, sol))
        {
            return true;
        }

        if (childInMaze(arr, n, x, y - 1, sol))
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
    int** array = new int*[7];   
    for (int i = 0; i < 7; i++) 
    {
        array[i] = new int[7];   
    }

    int Array[7][7] = 
    {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1}
    };

    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            array[i][j] = Array[i][j];
        }
    }

    int **sol = new int*[7];
    for (int i = 0; i < 7; i++)
    {
        sol[i] = new int[7];
        for (int j = 0; j < 7; j++)
        {
            sol[i][j] = 0;
        }
    }

    if (childInMaze(array, 7, 0, 0, sol))
    {
        cout << "Solution path:\n";
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
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

    for (int i = 0; i < 7; i++)
    {
        delete[] array[i];
        delete[] sol[i];
    }
    delete[] array;
    delete[] sol;

    return 0;
}

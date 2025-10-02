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

bool lionInMaze(int **arr, int n, int x, int y, int **sol)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, n, x, y))
    {
        sol[x][y] = 1;

        if (lionInMaze(arr, n, x + 1, y, sol))
        {
            return true;
        }

        if (lionInMaze(arr, n, x, y + 1, sol))
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
    int** array = new int*[5];   
    for (int i = 0; i < 5; i++) 
    {
        array[i] = new int[5];   
    }

    int Array[5][5] = 
    {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            array[i][j] = Array[i][j];
        }
    }

    int **sol = new int*[5];
    for (int i = 0; i < 5; i++)
    {
        sol[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            sol[i][j] = 0;
        }
    }

    if (lionInMaze(array, 5, 0, 0, sol))
    {
        cout << "Solution path:\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
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

    for (int i = 0; i < 5; i++)
    {
        delete[] array[i];
        delete[] sol[i];
    }
    delete[] array;
    delete[] sol;

    return 0;
}

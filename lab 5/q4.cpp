#include <iostream>
using namespace std;

bool isSafe(char **arr, int n, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (arr[i][col] == 'Q')
        {
            return false;
        }
    }

    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j--;
    }

    i = row, j = col;
    while (i >= 0 && j < n)
    {
        if (arr[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

bool NQueens(char **arr, int n, int row = 0)
{
    if (row >= n) {return true;}

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, n, row, col))
        {
            arr[row][col] = 'Q';  

            if (NQueens(arr, n, row + 1)) {return true;}

            arr[row][col] = '.'; 
        }
    }
    return false;
}

int main()
{
    char **sol = new char*[4];
    for (int i = 0; i < 4; i++)
    {
        sol[i] = new char[4];
        for (int j = 0; j < 4; j++)
        {
            sol[i][j] = '.';
        }
    }

    if (NQueens(sol, 4))
    {
        cout << "Solution aray:\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        delete[] sol[i];
    }
    delete[] sol;

    return 0;
}

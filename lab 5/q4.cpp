#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board , int n, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q') {return false;}
    }

    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q') {return false;}

        i--;
        j--;
    }

    i = row, j = col;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q') {return false;}

        i--;
        j++;
    }

    return true;
}

void NQueens(vector<string> &board, int n, int row, vector<vector<string>> &solutions)
{
    if (row == n) 
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, n, row, col))
        {
            board[row][col] = 'Q';  

            NQueens(board, n, row + 1, solutions);

            board[row][col] = '.'; 
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    NQueens(board, n, 0, solutions);  
    return solutions;  
}

int main()
{
    vector<vector<string>> solutions = solveNQueens(4);

        
    for (int i = 0; i < solutions.size(); i++) 
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < solutions[i].size(); j++)
        { 
            cout << solutions[i][j] << endl;
        }  
        cout << endl;
    } 
    
    return 0;
}

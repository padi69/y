#include <iostream>
using namespace std;

void printBoard(char board[][10], int n)
{
    cout << "----- Chess Board ----- " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char board[][10], int row, int col, int n)
{
    // Vertical up
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Left Diagonal Up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Right Diagonal Up
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(char board[][10], int row, int n)
{
    if (row == n)
    {
        printBoard(board, n);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';        // Place queen
            nQueens(board, row + 1, n); // Recursive call
            board[row][j] = 'X';        // Backtrack
        }
    }
}

int main()
{
    int n = 4;
    char board[10][10];

    // Initialize the board with 'X'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 'X';
        }
    }

    nQueens(board, 0, n);

    return 0;
}
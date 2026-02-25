#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<string> &board, int &row, int &colm, int n)
{
    // Horizontal check
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    // Vertical check
    for (int i = 0; i < n; i++)
    {
        if (board[i][colm] == 'Q')
        {
            return false;
        }
    }

    // Left diagonal check but only upper since we know that there is
    // nothing in the lower row
    for (int i = row, j = colm; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // This will check the upper right diagonnal as we can see the row are
    // increasing and the colm are decreasing
    for (int i = row, j = colm; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void nQueens(vector<vector<string>> &answer, int row, int n,
             vector<string> &board)
{
    if (n == row)
    {
        answer.push_back({board});
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (issafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            nQueens(answer, row + 1, n, board);
            board[row][j] = '.';
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<string>> answer;
    vector<string> board(n, string(n, '.'));
    nQueens(answer, 0, n, board);
    for (auto &ans : answer)
    {
        for (auto &row : ans)
        {
            cout << row << "" << endl;
        }
        cout << endl;
    }
    return 0;
}

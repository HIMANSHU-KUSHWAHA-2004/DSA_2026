#include <iostream>
#include <vector>
using namespace std;
bool checker(vector<vector<char>> &board, int row, int colm, char digi)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digi)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][colm] == digi)
        {
            return false;
        }
    }

    /*Checking for the grid of 3X3 the logic we will use that we have to
       find the starting of th grid in whhich our number lie if we find that
       then we can traverse the whole grid by usin the two for loop but for
       that we need to find in which grid we are since all have differnet
       starting point for that we will use some maths as we can see all the
       starting box of the grid have are the multiple of the 3 and follow some
       pattern */
    int starting_row = (row / 3) * 3;
    int starting_colm = (colm / 3) * 3;
    for (int i = starting_row; i <= starting_row + 2; i++)
    {
        for (int j = starting_colm; j <= starting_colm + 2; j++)
        {
            if (board[i][j] == digi)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoko_maker(vector<vector<char>> &board, int row, int colm)
{

    if (row == 9)
        return true;
    /*This is the base case since we are checking by the row wise
    and the 9th row does not exist*/

    if (colm == 9)
    {
        return sudoko_maker(board, row + 1, 0);
        /*This for when the colm become 9 that is at the end of the colm after that we will just increase the
        row and start the new colm from 0*/
    }

    if (board[row][colm] != '.')
    {
        return sudoko_maker(board, row, colm + 1);
        /*if there is already the number in the place then we will just
        move to the nexe place bu increasing the colm or row by +1
        and we are returnin the function so this will not come in the
        recurrsion call since we cannot chnage the actual number there*/
    }

    for (char digi = '1'; digi <= '9'; digi++)
    {
        /*Here we will check by row means we will solve it for each row so
        there would be total 9 rows so we can run a loop from 1 to <=9*/
        if (checker(board, row, colm, digi))
        {
            board[row][colm] = digi;
            if (sudoko_maker(board, row, colm + 1))
                return true;
            /*This statement is litte tricky like it will check if
            of the nextbox if there is No number in the block we can
            place then the loops get terminate and return a False
            will call the below statement to get execute that is the
            previous number we put was the wrong number */
            board[row][colm] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    if (!sudoko_maker(board, 0, 0))
    {
        cout << "This Sudoku is unsolvable." << endl;
        return ;
    }
    else
    {
        cout << "Sudoku solved successfully!" << endl;
    }
}
void printBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "---------------------\n";
        }

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};


    printBoard(board);
    solveSudoku(board);
    printBoard(board);

    return 0;
}

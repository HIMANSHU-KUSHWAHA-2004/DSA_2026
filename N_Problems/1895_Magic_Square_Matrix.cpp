#include <bits/stdc++.h>
using namespace std;

// Function to find the largest magic square in a grid
int largestMagicSquare(vector<vector<int>>& grid) {
    int row = grid.size();
    int colm = grid[0].size();

    // Prefix sums for rows and columns
    vector<vector<int>> rowprefix(row, vector<int>(colm));
    vector<vector<int>> colmprefix(row, vector<int>(colm));

    for (int i = 0; i < row; i++) {
        int temp = 0;
        for (int j = 0; j < colm; j++) {
            temp += grid[i][j];
            rowprefix[i][j] = temp;
        }
    }

    for (int j = 0; j < colm; j++) {
        int temp = 0;
        for (int i = 0; i < row; i++) {
            temp += grid[i][j];
            colmprefix[i][j] = temp;
        }
    }

    int Min_Possible_Side = min(row, colm);
    for (int side = Min_Possible_Side; side >= 2; side--) {
        for (int i = 0; i <= row - side; i++) {
            for (int j = 0; j <= colm - side; j++) {
                int Target_First_Row_Sum =
                    rowprefix[i][j + side - 1] -
                    ((j > 0) ? rowprefix[i][j - 1] : 0);

                bool rowflag = true, colmflag = true;

                // Check all row sums
                for (int r = i + 1; r < i + side; r++) {
                    int Row_sum = rowprefix[r][j + side - 1] - ((j > 0) ? rowprefix[r][j - 1] : 0);
                    if (Row_sum != Target_First_Row_Sum) {
                        rowflag = false;
                        break;
                    }
                }
                if (!rowflag) continue;

                // Check all column sums
                for (int c = j; c < j + side; c++) {
                    int Colm_sum = colmprefix[i + side - 1][c] - ((i > 0) ? colmprefix[i - 1][c] : 0);
                    if (Colm_sum != Target_First_Row_Sum) {
                        colmflag = false;
                        break;
                    }
                }
                if (!colmflag) continue;

                // Check diagonals
                int diagonal = 0, antidiagonal = 0;
                for (int k = 0; k < side; k++) {
                    diagonal += grid[i + k][j + k];
                    antidiagonal += grid[i + k][j + side - 1 - k];
                }

                if (diagonal == Target_First_Row_Sum && antidiagonal == Target_First_Row_Sum)
                    return side;
            }
        }
    }
    return 1; // Minimum magic square size is 1
}

// Example usage
int main() {
    vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4}
    };

    int result = largestMagicSquare(grid);
    cout << "Largest Magic Square size: " << result << endl;

    return 0;
}

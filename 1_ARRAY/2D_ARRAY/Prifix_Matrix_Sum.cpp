#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildPrefix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j - 1] - pref[i-1][j-1];
        }
    }
    return pref;
}

int subMatrixSum(vector<vector<int>> &pref, int r1, int c1, int r2, int c2)
{
    r1++;
    c1++;
    r2++;
    c2++;
    return pref[r2][c2]-pref[r1-1][c2]-pref[r2][c1-1]+pref[r1-1][c1-1];
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    vector<vector<int>> pref = buildPrefix(mat);

    cout << subMatrixSum(pref, 0, 0, 1, 1) << endl; // 45
}
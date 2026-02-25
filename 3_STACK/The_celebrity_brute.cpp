#include <bits\stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> mat)
{
    int n = mat.size();
    vector<int> know(n, 0);
    vector<int> know_by_other(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int maa = mat[i][j];
            know[i] += maa;
            know_by_other[j] += maa;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (know_by_other[i] == n && know[i] == 1)
            return i;
    }
    return -1;
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}};
    cout << celebrity(mat);
    return 0;
}
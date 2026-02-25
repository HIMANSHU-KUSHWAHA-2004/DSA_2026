#include <bits\stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> mato)
{
    int n = mato.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        if (mato[first][second] == 1)
            st.push(second);
        else
            st.push(first);
    }
    int celeb = st.top();
    for(int i = 0;i<n;i++){
        if(i != celeb && mato[i][celeb] != 1 || mato[celeb][i] == 1)
            return -1;
    }
    return st.top();
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}};
    cout << celebrity(mat);
    return 0;
}
#include <bits\stdc++.h>
using namespace std;
int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    stack<int> st;
    st.push(0);
    vector<int> lola(stock.size(), 1);
    for (int i = 1; i < stock.size(); i++)
    {
        while (!st.empty() && stock[i] >= stock[st.top()])
        {
            st.pop();
        }
        if (st.empty())
            lola[i] = i + 1;
        else
            lola[i] = i - st.top();
        st.push(i);
    }
    for (int i : lola)
        cout << i << " ";
}
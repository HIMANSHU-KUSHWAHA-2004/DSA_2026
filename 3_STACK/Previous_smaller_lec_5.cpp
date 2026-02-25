#include <bits\stdc++.h>
using namespace std;
int main()
/*HERE IN THIS CODE WE WILLL RETURN AN VECTOR WHICH CONTAIN THE ELEMENTS LEFT SIDE SMALLER NUMBER MEANS IT WILL HAVE A SMALLER 
NUMBER PRESENT IN THE LEFT SIDE WHCCIH OCCUR FIRST*/
{
    vector<int> lol = {3, 1, 0, 8, 6};
    stack<int> st;
    vector<int> ans(lol.size(),-1);
    st.push(lol[0]);
    for (int i = 1; i < lol.size(); i++)
    {
        while(!st.empty() && lol[i] < st.top()){
            st.pop();
        }

        if(st.empty())
            ans[i]  = -1;
        else    
            ans[i] = st.top();
        st.push(lol[i]);
    }
    for(int i : ans)
        cout << i << " " ;
}
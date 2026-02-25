#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> given = {6, 8, 0, 5, 8, 1, 3};
    int n = given.size();
    vector<int> nse(n, -1);  // default -1
    stack<int> st;           // will store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && given[st.top()] >= given[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nse[i] = given[st.top()];
        }
        st.push(i);
    }

    for (int x : nse) cout << x << " ";
}

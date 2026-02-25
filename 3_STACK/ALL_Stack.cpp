#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> heights = {4,1,6,18,10,8};
    int n = heights.size();

    vector<int> left_smaller(n), right_smaller(n),left_greater(n),right_greater(n);
    stack<int> st;

    // Right smaller boundary
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        if (st.empty())
            right_smaller[i] = n; // no smaller to right
        else
            right_smaller[i] = st.top();
        st.push(i);
    }

    // clear stack
    while (!st.empty()) st.pop();

    // Left smaller boundary
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        if (st.empty())
            left_smaller[i] = -1; // no smaller to left
        else
            left_smaller[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    // Left greater boundary
    for(int i =0;i<n;i++){
        while(!st.empty() && heights[i] >= heights[st.top()]){
            st.pop();
        }
        if(st.empty())
            left_greater[i] = -1;
        else    
            left_greater[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();

    //Right greater boundary
    for(int i = n - 1;i>=0;i--){
        while(!st.empty() && heights[i] >= heights[st.top()])
            st.pop();
        if(st.empty())
            right_greater[i] = n;
        else    
            right_greater[i] = st.top();
        st.push(i);
    }

    cout << "Left smaller indices: ";
    for (int x : left_smaller) cout << x << " ";
    cout << "\nRight smaller indices: ";
    for (int x : right_smaller) cout << x << " ";
    cout << endl;
    cout << "Left greater indices: ";
    for (int x : left_greater) cout << x << " ";
    cout << "\nRight greater indices: ";
    for (int x : right_greater) cout << x << " ";
    cout << endl;
}

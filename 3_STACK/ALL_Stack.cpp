#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> heights = {4, 1, 6, 18, 10, 8};
    int n = heights.size();

    vector<int> left_smaller(n), right_smaller(n);
    vector<int> left_greater(n), right_greater(n);

    stack<int> st;


    // =========================================================
    // 1. RIGHT SMALLER
    // =========================================================
    // Meaning:
    // For every element, find the INDEX of the nearest smaller
    // element on its RIGHT.
    //
    // Use case:
    // → Largest Rectangle in Histogram
    // → Finding right boundary
    // → Monotonic Stack problems
    //
    // Direction:
    // RIGHT → scan from right to left
    //
    // No smaller element → n
    // BECAUSE THE IT SIGNIFY THAT ITS OUTSIDE THE ARRAY
    //
    // Example:
    // [4, 1, 6]
    // For 4 → smaller on right = 1 (index 1)
    // =========================================================

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && heights[i] <= heights[st.top()])
            st.pop();

        if(st.empty())
            right_smaller[i] = n;
        else
            right_smaller[i] = st.top();

        st.push(i);
    }


    while(!st.empty())
        st.pop();


    // =========================================================
    // 2. LEFT SMALLER
    // =========================================================
    // Meaning:
    // For every element, find the INDEX of the nearest smaller
    // element on its LEFT.
    //
    // Use case:
    // → Largest Rectangle in Histogram
    // → Finding left boundary
    // → Previous Smaller Element (PSE)
    //
    // Direction:
    // LEFT → scan from left to right
    //
    // No smaller element → -1
    //
    // Example:
    // [4, 1, 6]
    // For 6 → smaller on left = 1 (index 1)
    // =========================================================

    for(int i = 0; i < n; i++) {

        while(!st.empty() && heights[i] <= heights[st.top()])
            st.pop();

        if(st.empty())
            left_smaller[i] = -1;
        else
            left_smaller[i] = st.top();

        st.push(i);
    }


    while(!st.empty())
        st.pop();


    // =========================================================
    // 3. LEFT GREATER
    // =========================================================
    // Meaning:
    // For every element, find the INDEX of the nearest greater
    // element on its LEFT.
    //
    // Use case:
    // → Previous Greater Element (PGE)
    // → Stock Span type problems
    // → Monotonic Stack problems
    //
    // Direction:
    // LEFT → scan from left to right
    //
    // No greater element → -1
    //
    // Example:
    // [4, 1, 6]
    // For 1 → greater on left = 4 (index 0)
    // =========================================================

    for(int i = 0; i < n; i++) {

        while(!st.empty() && heights[i] >= heights[st.top()])
            st.pop();

        if(st.empty())
            left_greater[i] = -1;
        else
            left_greater[i] = st.top();

        st.push(i);
    }


    while(!st.empty())
        st.pop();


    // =========================================================
    // 4. RIGHT GREATER
    // =========================================================
    // Meaning:
    // For every element, find the INDEX of the nearest greater
    // element on its RIGHT.
    //
    // Use case:
    // → Next Greater Element (NGE)
    // → Daily Temperatures
    // → Stock/price problems
    // → Monotonic Stack problems
    //
    // Direction:
    // RIGHT → scan from right to left
    //
    // No greater element → n
    //
    // Example:
    // [4, 1, 6]
    // For 1 → greater on right = 6 (index 2)
    // =========================================================

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && heights[i] >= heights[st.top()])
            st.pop();

        if(st.empty())
            right_greater[i] = n;
        else
            right_greater[i] = st.top();

        st.push(i);
    }


    // =========================================================
    // QUICK REVISION
    // =========================================================
    //
    // LEFT  → scan LEFT → RIGHT
    // RIGHT → scan RIGHT → LEFT
    //
    // SMALLER → pop >=
    // GREATER → pop <=
    //
    // Left boundary  → -1
    // Right boundary → n
    //
    // PSE → Left Smaller
    // NSE → Right Smaller
    // PGE → Left Greater
    // NGE → Right Greater
    //
    // IMPORTANT:
    // These arrays store the INDEX, not the value.
    //
    // =========================================================


    cout << "Left Smaller: ";
    for(int x : left_smaller)
        cout << x << " ";

    cout << "\nRight Smaller: ";
    for(int x : right_smaller)
        cout << x << " ";

    cout << "\nLeft Greater: ";
    for(int x : left_greater)
        cout << x << " ";

    cout << "\nRight Greater: ";
    for(int x : right_greater)
        cout << x << " ";

    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 1405: Longest Happy String

Problem:
Given a, b, c counts of 'a', 'b', 'c'.
Build the longest string such that it does NOT contain "aaa", "bbb", "ccc".
*/

class Solution {
public:
    typedef pair<int, char> P;

    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;

        if (a > 0) pq.push(P(a, 'a'));
        if (b > 0) pq.push(P(b, 'b'));
        if (c > 0) pq.push(P(c, 'c'));

        string res = "";

        while (!pq.empty()) {
            P first = pq.top();
            pq.pop();

            int cnt1 = first.first;
            char ch1 = first.second;

            int n = (int)res.size();

            // If adding ch1 makes 3 same letters in a row
            if (n >= 2 && res[n - 1] == ch1 && res[n - 2] == ch1) {
                if (pq.empty()) break;

                P second = pq.top();
                pq.pop();

                int cnt2 = second.first;
                char ch2 = second.second;

                res.push_back(ch2);
                cnt2--;

                if (cnt2 > 0) pq.push(P(cnt2, ch2));

                // put first back (not used)
                pq.push(P(cnt1, ch1));
            }
            else {
                res.push_back(ch1);
                cnt1--;

                if (cnt1 > 0) pq.push(P(cnt1, ch1));
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    int a = 1, b = 1, c = 7;
    string ans = obj.longestDiverseString(a, b, c);

    cout << "Longest Happy String = " << ans << "\n";
    cout << "Length = " << ans.size() << "\n";

    return 0;
}
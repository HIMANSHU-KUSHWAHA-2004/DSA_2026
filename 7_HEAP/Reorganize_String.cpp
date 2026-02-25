#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, char> P;
    typedef priority_queue<P> PQ;

    string reorganizeString(string s) {

        PQ pq;
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        if (!pq.empty() && pq.top().first > (s.size() + 1) / 2) {
            return "";
        }

        string result = "";

        while (!pq.empty()) {

            P top1 = pq.top();
            pq.pop();

            int f1 = top1.first;
            char ch1 = top1.second;

            if (!result.empty() && result.back() == ch1) {

                if (pq.empty()) return "";

                P top2 = pq.top();
                pq.pop();

                int f2 = top2.first;
                char ch2 = top2.second;

                result += ch2;
                f2--;

                if (f2 > 0)
                    pq.push({f2, ch2});

                pq.push({f1, ch1});
            }
            else {
                result += ch1;
                f1--;

                if (f1 > 0)
                    pq.push({f1, ch1});
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    string ans = obj.reorganizeString(s);

    if (ans == "")
        cout << "Not possible to reorganize\n";
    else
        cout << "Reorganized string: " << ans << endl;

    return 0;
}
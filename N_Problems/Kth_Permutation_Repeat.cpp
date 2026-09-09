#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> fact;

    void init(int n) {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    long long countPerm(map<char,int>& freq) {
        int total = 0;
        for (auto &p : freq) total += p.second;

        long long res = fact[total];
        for (auto &p : freq) {
            res /= fact[p.second];
        }
        return res;
    }

    string kthPermutation(string s, int k) {
        int n = s.size();
        init(n);

        map<char,int> freq;
        for (char c : s) freq[c]++;

        string ans = "";

        while (ans.size() < n) {
            for (auto &p : freq) {
                char ch = p.first;
                if (p.second == 0) continue;

                freq[ch]--;

                long long cnt = countPerm(freq);

                if (k > cnt) {
                    k -= cnt;      // skip this block
                    freq[ch]++;    // restore
                } else {
                    ans += ch;     // pick this char
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    string result = obj.kthPermutation(s, k);

    if (result == "") {
        cout << "Invalid k (greater than total permutations)\n";
    } else {
        cout << "K-th permutation: " << result << endl;
    }

    return 0;
}
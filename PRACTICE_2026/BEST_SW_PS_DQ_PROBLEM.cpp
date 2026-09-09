/*best*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    unordered_map<long long, int> freq;

    deque<int> dq;

    int l = 0, distinct = 0;
    long long ans = 0;

    dq.push_back(0); // prefix[0]

    for (int r = 0; r < n; r++) {

        if (freq[a[r]] == 0) distinct++;
        freq[a[r]]++;

        while (distinct > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) distinct--;
            l++;
        }

        // remove invalid prefix indices
        while (!dq.empty() && dq.front() < l)
            dq.pop_front();

        // maintain increasing prefix
        while (!dq.empty() &&
               prefix[dq.back()] >= prefix[r + 1])
            dq.pop_back();

        dq.push_back(r + 1);

        // best answer
        ans = max(ans, prefix[r + 1] - prefix[dq.front()]);
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void partitioning(int start, string &s,
                  vector<string> &temp,
                  vector<vector<string>> &answer) {

    // Base case
    if (start == s.size()) {
        answer.push_back(temp);
        return;
    }

    // Try every possible partition
    for (int i = start; i < s.size(); i++) {

        if (isPalindrome(s, start, i)) {

            // Choose
            temp.push_back(s.substr(start, i - start + 1));

            // Explore
            partitioning(i + 1, s, temp, answer);

            // Undo
            temp.pop_back();
        }
    }
}

int main() {

    string s = "aaba";

    vector<string> temp;
    vector<vector<string>> answer;

    partitioning(0, s, temp, answer);

    for (auto &x : answer) {
        for (auto &y : x)
            cout << y << " ";

        cout << endl;
    }

    return 0;
}
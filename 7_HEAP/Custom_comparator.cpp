#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MaxBySecond {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
        //IF THE a.first < b.first THAT MEANS a.first HAS LOWER PRIORITY THE b.first SO B MOVE UPWARD MEANS GOING TO THE TOP
    }
};

struct MinBySecond {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;
            return a.second > b.second;
            //IF THE a.first > b.first THAT MEANS a.first HAS LOWER PRIORITY THE b.first SO B MOVE UPWARD MEANS GOING TO THE TOP
    }
};

int main() {

    priority_queue<pair<int,int>, vector<pair<int,int>>, MaxBySecond> maxH;
    priority_queue<pair<int,int>, vector<pair<int,int>>, MinBySecond> minH;

    vector<pair<int,int>> items = {
        {1000, 5},
        {1, 2},
        {9999, 7},
        {50, 7},
        {200, 2}
    };

    for (int i = 0; i < items.size(); i++) {
        maxH.push(items[i]);
        minH.push(items[i]);
    }

    cout << "MAX heap by second:\n";
    while (!maxH.empty()) {
        pair<int,int> temp = maxH.top();
        cout << "{" << temp.first << ", " << temp.second << "}\n";
        maxH.pop();
    }

    cout << "\nMIN heap by second:\n";
    while (!minH.empty()) {
        pair<int,int> temp = minH.top();
        cout << "{" << temp.first << ", " << temp.second << "}\n";
        minH.pop();
    }

    return 0;
}
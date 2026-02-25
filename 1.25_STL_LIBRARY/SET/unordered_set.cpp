#include<bits/stdc++.h>
#include<unordered_set>
// using namespace std;
// #include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> us = {1, 2, 3, 4, 5};
    
    // Accessing third element
    auto it = next(us.begin(), 2);
    cout << *it;
    return 0;
}

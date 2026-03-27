#include <bits/stdc++.h>
using namespace std;

int main() {

    // ---------------- VECTOR ----------------
    vector<int> v = {10, 20, 30, 40};

    // begin() → points to first element
    auto it1 = v.begin();

    // * → dereference → get value
    cout << *it1 << endl;   // 10

    // Move iterator forward
    it1++;
    cout << *it1 << endl;   // 20


    // Loop using iterator
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";   // print each value
    }
    cout << endl;


    // end() → points AFTER last element
    // *v.end() ❌ INVALID (never do this)


    // ---------------- SET ----------------
    set<int> s = {5, 1, 10, 2};

    // set is always sorted
    // s = {1, 2, 5, 10}

    auto it2 = s.begin();   // points to smallest
    cout << *it2 << endl;   // 1

    // erase first element
    s.erase(s.begin());     // removes 1

    // print set
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    // ---------------- PAIR ----------------
    pair<int,int> p = {100, 200};

    cout << p.first << endl;   // 100
    cout << p.second << endl;  // 200


    // ---------------- SET OF PAIRS ----------------
    set<pair<int,int>> sp;

    sp.insert({2, 100});
    sp.insert({1, 200});
    sp.insert({3, 50});

    // sorted by first element automatically
    // sp = { {1,200}, {2,100}, {3,50} }

    auto it3 = sp.begin();

    // Access using ->
    cout << it3->first << endl;   // 1
    cout << it3->second << endl;  // 200

    // Same thing using *
    cout << (*it3).first << endl;
    cout << (*it3).second << endl;


    // ---------------- IMPORTANT PATTERN ----------------
    // Getting smallest pair (used in Dijkstra)

    auto smallest = *(sp.begin());

    cout << smallest.first << " " << smallest.second << endl;


    // ---------------- ERASE USING VALUE ----------------
    sp.erase({2,100});   // removes this pair


    // ---------------- CHECK EMPTY ----------------
    if(sp.begin() == sp.end()){
        cout << "Empty" << endl;
    }


    // ---------------- REVERSE ITERATOR ----------------
    for(auto it = v.rbegin(); it != v.rend(); it++){
        cout << *it << " ";   // reverse print
    }
    cout << endl;


    return 0;
}
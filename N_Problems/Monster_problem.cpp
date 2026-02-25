/*
Problem: Monster Monster
You have encountered an army of N monsters, each with a certain amount of health points (HP). Your goal is to defeat them all by attacking exactly one monster per day, where the attack stat A is greater than or equal to the HP of the monster you attack. After each day, the HP of every alive monster increases by a fixed value X.
Input Format
The first line contains an integer T, representing the number of test cases.
Each test case consists of two lines:
Two integers N (number of monsters) and X (HP increase per day).
A list of integers representing the initial HP values of the N monsters.
Output Format
For each test case, output a single integer on a new line: the minimum attack stat A required to kill all the monsters.
Constraints
1 ≤ T ≤ 2 × 10^5
1 ≤ N ≤ 2 × 10^5
1 ≤ X ≤ 10^9
1 ≤ H_i ≤ 10^9
The sum of N over all test cases won't exceed 2 × 10^5.
Example
Test Case 1:
You need an attack stat of 21 to defeat all monsters:
Day 1: Kill the monster with HP 2 (others' HP increase by 10).
Day 2: Kill the monster with HP 13 (others' HP increase by 10).
Day 3: Kill the remaining monster with HP 21.
Test Case 2:
An attack stat of 10 is sufficient to kill all monsters in any order.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    
}
#include <bits/stdc++.h>
using namespace std;

long long Binary_exponentiation(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long half = Binary_exponentiation(a, b/2);
    long long result = half * half;

    if (b % 2 == 1)
        result *= a;

    return result;
}

int main()
{
    long long a = 2;
    long long b = 50;

    cout << Binary_exponentiation(a,b);
}
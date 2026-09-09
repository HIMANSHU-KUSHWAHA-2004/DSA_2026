#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 50; // find primes up to n
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
}
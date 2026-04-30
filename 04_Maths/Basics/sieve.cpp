#include <bits/stdc++.h>
using namespace std;

/*
Sieve of Eratosthenes
Find all primes up to n
Time: O(n log log n)
*/

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    int n = 30;

    vector<int> primes = sieve(n);

    for (int p : primes) cout << p << " ";

    return 0;
}

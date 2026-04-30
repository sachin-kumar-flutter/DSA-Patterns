#include <bits/stdc++.h>
using namespace std;

/*
Check if a number is prime
Time: O(sqrt(n))
*/

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main() {
    int n = 29;

    cout << (isPrime(n) ? "Prime" : "Not Prime") << endl;

    return 0;
}

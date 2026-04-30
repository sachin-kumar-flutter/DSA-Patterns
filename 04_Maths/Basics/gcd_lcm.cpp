#include <bits/stdc++.h>
using namespace std;

/*
GCD & LCM
- GCD: Greatest Common Divisor
- LCM: Least Common Multiple
*/

// Euclidean Algorithm for GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 12, b = 18;

    cout << "GCD: " << gcd(a, b) << endl;
    cout << "LCM: " << lcm(a, b) << endl;

    return 0;
}

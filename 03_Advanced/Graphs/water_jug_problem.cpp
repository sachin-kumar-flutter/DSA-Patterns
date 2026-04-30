#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------
WATER JUG PROBLEM (MIN OPERATIONS)
-----------------------------------------

Given two jugs of capacity m and n litres,
find minimum steps to measure exactly d litres.

Allowed operations:
1. Fill a jug
2. Empty a jug
3. Pour from one jug to another

-----------------------------------------
APPROACH:
-----------------------------------------

1. Mathematical condition:
   - Solution exists only if:
        d <= max(m, n)
        d % gcd(m, n) == 0

2. Try both possibilities:
   - Pour from m → n
   - Pour from n → m

3. Simulation (Greedy):
   - Fill source jug
   - Pour into destination jug
   - If source empty → refill
   - If destination full → empty
   - Count steps

4. Return minimum of both cases

-----------------------------------------
TIME COMPLEXITY: O(max(m, n))
SPACE COMPLEXITY: O(1)
-----------------------------------------
*/

int pour(int fromCap, int toCap, int d) {
    int from = fromCap;  // initially fill source jug
    int to = 0;          // destination jug is empty
    int step = 1;        // first step = filling

    // continue until we get d litres in any jug
    while (from != d && to != d) {

        // pour water from source to destination
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;

        // check if we reached the target
        if (from == d || to == d)
            break;

        // if source becomes empty, refill it
        if (from == 0) {
            from = fromCap;
            step++;
        }

        // if destination becomes full, empty it
        if (to == toCap) {
            to = 0;
            step++;
        }
    }

    return step;
}

int minSteps(int m, int n, int d) {

    // if not possible
    if (d > max(m, n)) return -1;
    if (d % __gcd(m, n) != 0) return -1;

    // take minimum of both directions
    return min(pour(m, n, d), pour(n, m, d));
}

int main() {
    int m = 3, n = 5, d = 4;

    int result = minSteps(m, n, d);

    if (result == -1)
        cout << "Not possible\n";
    else
        cout << "Minimum steps: " << result << endl;

    return 0;
}

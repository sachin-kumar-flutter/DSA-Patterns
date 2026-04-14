/*
---------------------------------------------------------
Problem: Rotate Array (Left Rotation by d positions)
Approach: Juggling Algorithm
---------------------------------------------------------

Idea:
Instead of reversing, we divide the array into cycles
based on gcd(n, d). Each cycle is rotated individually.

Key Concept:
- Number of cycles = gcd(n, d)
- Each element moves to (i + d) % n

Process:
1. Find gcd(n, d)
2. For each cycle:
   - Store starting element
   - Move elements by d positions
   - Continue until cycle completes
   - Place stored element at correct position

Example:
Input:  [1, 2, 3, 4, 5, 6, 7, 8], d = 2
gcd(8,2) = 2 → 2 cycles

Cycle 1: indices (0 → 2 → 4 → 6 → 0)
Cycle 2: indices (1 → 3 → 5 → 7 → 1)

Time Complexity: O(n)
Space Complexity: O(1)  // In-place rotation

Notes:
- Always take d = d % n
- Based on cycle decomposition using GCD
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform left rotation using juggling algorithm
void rotateLeft(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;  // handle large d

    int g = __gcd(n, d); // number of cycles

    // Process each cycle
    for (int i = 0; i < g; i++) {
        int temp = arr[i];  // store first element of cycle
        int j = i;

        while (true) {
            int k = (j + d) % n;

            if (k == i) break;

            arr[j] = arr[k]; // move element
            j = k;
        }

        arr[j] = temp; // place stored element
    }
}

// Driver code (optional for testing)
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int d = 2;

    rotateLeft(arr, d);

    for (int x : arr) cout << x << " ";
    return 0;
}

/*
---------------------------------------------------------
Problem: Rotate Array (Left Rotation by d positions)
Approach: Reversal Algorithm
---------------------------------------------------------

Idea:
Instead of shifting elements one by one (O(n*d)),
we use reversal to achieve rotation in O(n) time.

Steps:
1. Reverse first d elements
2. Reverse remaining (n - d) elements
3. Reverse the entire array

Example:
Input:  [1, 2, 3, 4, 5, 6, 7], d = 2
Step 1: [2, 1, 3, 4, 5, 6, 7]
Step 2: [2, 1, 7, 6, 5, 4, 3]
Step 3: [3, 4, 5, 6, 7, 1, 2]

Time Complexity: O(n)
Space Complexity: O(1)  // In-place rotation

Notes:
- Always take d = d % n to handle large rotations
- Right rotation can be done by converting it into left rotation:
  rightRotate(d) = leftRotate(n - d)
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a part of the array
void reverseArray(vector<int>& arr, int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Function to perform left rotation by d positions
void rotateLeft(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;  // handle cases where d > n

    // Step 1: Reverse first d elements
    reverseArray(arr, 0, d - 1);

    // Step 2: Reverse remaining elements
    reverseArray(arr, d, n - 1);

    // Step 3: Reverse whole array
    reverseArray(arr, 0, n - 1);
}

// Driver code (optional for testing)
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;

    rotateLeft(arr, d);

    for (int x : arr) cout << x << " ";
    return 0;
}

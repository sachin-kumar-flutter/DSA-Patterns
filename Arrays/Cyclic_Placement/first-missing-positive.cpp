#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Smallest Missing Positive

    Intuition:
    - We only care about numbers in range [1, n]
    - Place each number x at index (x - 1)
    - Use array itself as a marker (negative = present)

    Key Idea:
    Treat index as "seat" and value as "person"
    Person x should sit at seat (x-1)

    Steps:
    1. Remove useless numbers (<=0 or >n)
    2. Mark presence using negative sign
    3. First positive index => missing number
*/

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Ignore useless numbers
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = n + 1;  // mark as invalid
        }
    }

    // Step 2: Mark presence
    for (int i = 0; i < n; i++) {
        int x = abs(nums[i]);

        // Only mark if within range
        if (x >= 1 && x <= n) {
            // Mark index (x-1) as negative => x is present
            nums[x - 1] = -abs(nums[x - 1]);
        }
    }

    // Step 3: Find first missing
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return i + 1;  // missing number
        }
    }

    // If all positions filled
    return n + 1;
}

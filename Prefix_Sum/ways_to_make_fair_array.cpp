/*
Problem: Ways to Make a Fair Array

You are given an integer array nums.
You can remove exactly one element. After removal, the array is "fair"
if sum of elements at even indices == sum of elements at odd indices.

Return the number of indices whose removal makes the array fair.

------------------------------------------------------------

Approach (Prefix Sum + Parity Flip):

Key Observation:
When we remove an element at index i:
- All elements after i shift left by 1
- This causes their index parity to flip (even <-> odd)

So:
- Left side (0 to i-1) → remains same
- Right side (i+1 to n-1) → parity flips

We maintain:
- totalEven, totalOdd → sum of full array
- leftEven, leftOdd → sum of left part while iterating

For each index i:
1. Remove nums[i] from total → now totals represent RIGHT side
2. Compute new sums after removal:
   newEven = leftEven + totalOdd   (right odd becomes even)
   newOdd  = leftOdd  + totalEven  (right even becomes odd)
3. If equal → valid index
4. Add nums[i] to left sums

Time Complexity: O(n)
Space Complexity: O(1)

Memory Trick:
"Left stays same, Right flips parity"
------------------------------------------------------------
*/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int totalEven = 0, totalOdd = 0;

        // Step 1: Calculate total sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += nums[i];
            else totalOdd += nums[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        // Step 2: Try removing each index
        for (int i = 0; i < n; i++) {

            // Remove current element from total (now totals = right side)
            if (i % 2 == 0) totalEven -= nums[i];
            else totalOdd -= nums[i];

            // Compute new sums after removal
            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd  + totalEven;

            // Check if fair
            if (newEven == newOdd) count++;

            // Add current element to left side
            if (i % 2 == 0) leftEven += nums[i];
            else leftOdd += nums[i];
        }

        return count;
    }
};

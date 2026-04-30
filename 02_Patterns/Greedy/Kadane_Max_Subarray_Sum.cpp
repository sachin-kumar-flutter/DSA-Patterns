/*
    Pattern: Greedy (Kadane’s Algorithm)
    Problem: Maximum Subarray Sum

    Approach:
    ----------
    We iterate through the array while maintaining two variables:

    1. curr (current sum):
       - Represents the maximum subarray sum ending at current index
       - At each step, we decide:
            → Start new subarray from current element
            → OR extend previous subarray

       Formula:
            curr = max(arr[i], curr + arr[i])

    2. ans (global maximum):
       - Stores the maximum subarray sum found so far

    Key Insight:
    ------------
    If the current sum becomes negative, it is useless for future subarrays,
    so we effectively restart from the current element.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int ans = arr[0];   // stores overall maximum
        int curr = 0;       // stores current subarray sum

        for(int i = 0; i < arr.size(); i++) {
            // Decide whether to start new subarray or extend existing one
            curr = max(arr[i], curr + arr[i]);

            // Update global maximum
            ans = max(ans, curr);
        }

        return ans;
    }
};

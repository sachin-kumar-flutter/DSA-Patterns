/*
Problem: Smallest Stable Index I (LeetCode)

Description:
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as:
    max(nums[0..i]) - min(nums[i..n - 1])

Where:
- max(nums[0..i]) is the maximum element from index 0 to i.
- min(nums[i..n-1]) is the minimum element from index i to n-1.

An index i is called stable if its instability score is <= k.

Return the smallest stable index. If no such index exists, return -1.

Time Complexity: O(n)
Space Complexity: O(n) → reduced (only one array instead of two)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: suffix min
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        // Step 2: traverse + maintain prefix max
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
        return -1;
    }
};

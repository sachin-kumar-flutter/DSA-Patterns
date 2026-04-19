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

Approach:
- Use prefix array to store maximum till index i
- Use suffix array to store minimum from index i to end
- Check for smallest i such that:
      prefix_max[i] - suffix_min[i] <= k

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maximum(n), minimum(n);

        // prefix max
        maximum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maximum[i] = max(maximum[i - 1], nums[i]);
        }

        // suffix min
        minimum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minimum[i] = min(minimum[i + 1], nums[i]);
        }

        // find smallest stable index
        for (int i = 0; i < n; i++) {
            if (maximum[i] - minimum[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};

// Problem: Minimize Maximum Pair Sum in Array
// Pattern: Greedy + Two Pointers
// Difficulty: Medium

// Key Idea:
// We want to minimize the maximum pair sum.
// To achieve this, we pair the smallest element with the largest element.

// Intuition:
// - If we pair large numbers together, max sum increases
// - Pairing smallest with largest balances the sums
// - This ensures the maximum pair sum is minimized

// Approach:
// - Sort the array
// - Use two pointers: one at start, one at end
// - Compute pair sum and track the maximum

// Why Greedy?
// Pairing extremes at each step leads to globally optimal solution

// Time Complexity: O(n log n)
// Space Complexity: O(1)

// Tags: Greedy, Two Pointers, Sorting

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ans = INT_MIN;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};

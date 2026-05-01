// Problem: LeetCode 396 - Rotate Function
// Approach: Mathematical Transformation (Recurrence Relation)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;   // total sum of array
        int f = 0;     // F(0)

        // Step 1: Calculate sum and F(0)
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }

        int ans = f;

        // Step 2: Use recurrence relation
        // F(k) = F(k-1) + sum - n * nums[n-k]
        for(int k = 1; k < n; k++) {
            f = f + sum - n * nums[n - k];

            // Track maximum value
            ans = max(ans, f);
        }

        return ans;
    }
};

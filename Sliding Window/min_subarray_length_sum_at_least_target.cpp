class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding Window Approach
        // Goal: Find smallest length subarray with sum >= target
        
        int start = 0, end = 0;
        int ans = INT_MAX;
        int sum = 0;

        while (end < nums.size()) {
            // Expand window by adding current element
            sum += nums[end];

            // Shrink window while condition is satisfied
            while (sum >= target) {
                // Update answer (window size)
                ans = min(ans, end - start + 1);

                // Remove left element and move start
                sum -= nums[start];
                start++;
            }

            // Move end pointer
            end++;
        }

        // If no valid subarray found, return 0
        return ans == INT_MAX ? 0 : ans;
    }
};

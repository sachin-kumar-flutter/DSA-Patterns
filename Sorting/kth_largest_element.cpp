class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Find min and max values
        int minValue = INT_MAX;
        int maxValue = INT_MIN;

        for(int x : nums) {
            minValue = min(minValue, x);
            maxValue = max(maxValue, x);
        }

        // Step 2: Create frequency array
        // Size = range of values
        vector<int> counter(maxValue - minValue + 1, 0);

        // Step 3: Store frequency of each number
        for(int i = 0; i < n; i++) {
            counter[nums[i] - minValue]++;
        }

        // Step 4: Traverse from largest to smallest
        // Reduce k until we reach kth largest
        for(int i = counter.size() - 1; i >= 0; i--) {
            k -= counter[i];

            if(k <= 0) {
                return i + minValue;
            }
        }

        return -1; // fallback (should not happen)
    }
};

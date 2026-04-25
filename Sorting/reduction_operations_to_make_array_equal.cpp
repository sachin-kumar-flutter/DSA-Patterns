class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        // Step 1: Sort the array
        // Reason: Helps group equal elements and process from largest to smallest
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int operations = 0;

        // Step 2: Traverse from right (largest elements)
        for (int i = n - 1; i > 0; i--) {
            
            // If current element is different from previous,
            // it means we found a new smaller value
            if (nums[i] != nums[i - 1]) {
                
                // All elements from index i to n-1 need one extra operation
                operations += (n - i);
            }
        }

        return operations;
    }
};

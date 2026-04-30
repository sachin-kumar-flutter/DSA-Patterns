/*
Problem: Count Subarrays Where Maximum Element Appears at Least K Times

Approach:
1. First, find the maximum element in the array.
2. Use sliding window technique:
   - Expand window using 'end' pointer.
   - Count occurrences of the maximum element.
3. When count >= k:
   - All subarrays starting from 'start' to any index >= end are valid.
   - So, add (n - end) to the answer.
4. Shrink window from the left to explore new subarrays.

Key Insight:
If a window satisfies the condition (count >= k), then extending it further
will also satisfy it → hence we add (n - end).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long ans = 0;
        
        // Step 1: Find the maximum element
        int maximum = INT_MIN;
        for(int num : nums){
            maximum = max(maximum, num);
        }
        
        int start = 0;
        int count = 0; // count of maximum element in current window
        
        // Step 2: Sliding window
        for(int end = 0; end < n; end++){
            
            if(nums[end] == maximum){
                count++;
            }
            
            // Step 3: When condition is satisfied
            while(count >= k){
                ans += (n - end);
                
                if(nums[start] == maximum){
                    count--;
                }
                start++;
            }
        }
        
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------
PROBLEM:
Count number of subarrays where:
    sum(subarray) * length(subarray) < k
---------------------------------------------------

APPROACH: Sliding Window (Two Pointers)

Key Idea:
- Maintain a window [start, end]
- Keep track of sum of current window
- Check condition:
      sum * length < k

Steps:
1. Expand window by increasing 'end'
2. Add nums[end] to sum
3. If condition breaks:
      shrink window from left (start++)
4. For each valid window:
      number of valid subarrays ending at 'end' =
      (end - start + 1)

Why?
- All subarrays ending at 'end' and starting from
  any index between [start, end] are valid

---------------------------------------------------
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
---------------------------------------------------
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long ans = 0;

        int start = 0;

        for(int end = 0; end < nums.size(); end++) {

            // Expand window
            sum += nums[end];

            // Shrink window until condition satisfied
            while(sum * (end - start + 1LL) >= k) {
                sum -= nums[start];
                start++;
            }

            // Count valid subarrays ending at 'end'
            ans += (end - start + 1);
        }

        return ans;
    }
};

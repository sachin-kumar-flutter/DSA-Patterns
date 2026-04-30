/*
Problem: Continuous Subarray Sum

Approach:
---------
We need to check if there exists a subarray of length >= 2
whose sum is a multiple of k.

Key Observation:
----------------
If two prefix sums have the same remainder when divided by k,
then the subarray between them has sum divisible by k.

i.e.,
(prefix[j] - prefix[i]) % k == 0
=> prefix[j] % k == prefix[i] % k

Algorithm:
-----------
1. Use a hashmap to store: remainder → first index where it appeared
2. Initialize map with (0 → -1) to handle subarrays starting from index 0
3. Traverse the array:
   - Maintain running prefix sum
   - Compute remainder (prefix % k)
   - If remainder already exists:
        -> check if subarray length >= 2
        -> if yes, return true
   - Else store the remainder with current index

Edge Cases:
------------
- If k == 0:
    We cannot take modulo, so check for at least two consecutive zeros.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // Edge case: k == 0
        if (k == 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            }
            return false;
        }

        unordered_map<int, int> mp;
        mp[0] = -1; // handles subarray from index 0

        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            int mod = prefix % k;

            // handle negative modulo (safe practice)
            if (mod < 0) mod += k;

            if (mp.count(mod)) {
                // check length >= 2
                if (i - mp[mod] >= 2)
                    return true;
            } else {
                // store first occurrence only
                mp[mod] = i;
            }
        }

        return false;
    }
};

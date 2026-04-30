#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------
PROBLEM:
Count number of subarrays whose sum is divisible by k
---------------------------------------

APPROACH:
We use Prefix Sum + HashMap

Key Idea:
If two prefix sums have the same remainder when divided by k,
then their difference (subarray sum) is divisible by k.

Why?
(prefixSum[j] - prefixSum[i]) % k == 0
=> prefixSum[j] % k == prefixSum[i] % k

So:
- Track frequency of each remainder
- If same remainder appears again → valid subarray exists

IMPORTANT TRICK:
Modulo can be negative in C++, so normalize it:

    remainder = ((prefixSum % k) + k) % k;

This ensures remainder is always in range [0, k-1]

---------------------------------------
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(k)
---------------------------------------
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0;
        int count = 0;

        unordered_map<int, int> mp;

        // Base case: remainder 0 seen once
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Normalize remainder
            int remainder = ((prefixSum % k) + k) % k;

            // If this remainder was seen before,
            // add its frequency to count
            if(mp.count(remainder)) {
                count += mp[remainder];
            }

            // Update frequency
            mp[remainder]++;
        }

        return count;
    }
};

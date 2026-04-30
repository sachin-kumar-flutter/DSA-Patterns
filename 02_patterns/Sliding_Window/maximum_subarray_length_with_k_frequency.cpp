#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // Sliding Window + HashMap
        // Goal: Find the maximum length subarray such that
        // no element appears more than k times

        unordered_map<int, int> freq;

        int start = 0, end = 0;
        int maxLen = 0;

        while (end < nums.size()) {
            // Include current element
            freq[nums[end]]++;

            // If frequency exceeds k, shrink window
            while (freq[nums[end]] > k) {
                freq[nums[start]]--;
                start++;
            }

            // Update maximum length
            maxLen = max(maxLen, end - start + 1);

            end++;
        }

        return maxLen;
    }
};

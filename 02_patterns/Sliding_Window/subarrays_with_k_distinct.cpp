/*
🔹 Problem: Subarrays with K Distinct Integers

🔹 Approach:
We use a sliding window technique with a key observation:

👉 Number of subarrays with exactly K distinct elements =
   Number of subarrays with at most K distinct
   - Number of subarrays with at most (K-1) distinct

So, we implement a helper function `atMostK()`.

🔹 How atMostK works:
- Expand the window using `end`
- Use a hashmap to track frequency of elements
- If a new distinct element is added, decrement k
- If k becomes negative, shrink window from `start`
- For each valid window, add (end - start + 1) to answer

🔹 Time Complexity: O(N)
🔹 Space Complexity: O(N)

🔹 Key Insight:
This is a classic sliding window pattern and commonly asked in interviews.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int start = 0, ans = 0;

        for(int end = 0; end < nums.size(); end++) {
            if(freq[nums[end]] == 0) k--;   // new distinct element
            freq[nums[end]]++;

            while(k < 0) {
                freq[nums[start]]--;
                if(freq[nums[start]] == 0) k++;  // distinct removed
                start++;
            }

            ans += end - start + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

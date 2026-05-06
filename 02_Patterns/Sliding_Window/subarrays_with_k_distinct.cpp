/*
-------------------------------------
🧩 Problem: Subarrays with K Different Integers
📂 Category: Sliding Window (Advanced Counting)
🧠 Concept: atMost(k) trick

⚡ Approach:
- Count subarrays with at most k distinct integers
- Exact k distinct =
    atMost(k) - atMost(k - 1)

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(k)

🎯 Key Idea:
- Convert exact count problem into two easier problems

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            // Shrink window if distinct count exceeds k
            while(freq.size() > k) {

                freq[nums[left]]--;

                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            // Count valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
    }
};

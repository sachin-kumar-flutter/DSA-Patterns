/*
-------------------------------------
🧩 Problem: Next Permutation
📂 Category: Arrays (Pattern - Permutation)
🧠 Concept: Lexicographical Permutation

⚡ Approach:
1. Traverse from right and find the first index where nums[i] < nums[i+1]
   → This is the "breakpoint" (index)

2. If no such index exists:
   → The array is in descending order
   → Reverse the entire array (smallest permutation)

3. Otherwise:
   → Traverse from right again and find the first element > nums[index]
   → Swap it with nums[index]

4. Reverse the subarray after index
   → To get the next smallest lexicographic order

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Make the smallest possible increase to get next permutation

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find breakpoint
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse whole array
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element and swap
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[index], nums[i]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

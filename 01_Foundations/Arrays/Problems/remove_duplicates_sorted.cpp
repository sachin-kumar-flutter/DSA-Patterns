/*
-------------------------------------
🧩 Problem: Remove Duplicates from Sorted Array
📂 Category: Arrays (Foundation)
🧠 Concept: Two Pointers (Slow & Fast)

⚡ Approach:
- Use two pointers:
    → i: last unique element index
    → j: scans the array
- When nums[j] != nums[i]:
    → move i forward and copy nums[j] to nums[i]
- Return i + 1 as new length

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Keep only unique elements by overwriting in-place

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

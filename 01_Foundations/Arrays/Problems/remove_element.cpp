/*
-------------------------------------
🧩 Problem: Remove Element
📂 Category: Arrays (Foundation)
🧠 Concept: Two Pointer / In-place Filtering

⚡ Approach:
- Maintain pointer k for next valid position
- Traverse array:
    → If element != val, place it at index k
    → Increment k
- Final k = new length of array

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Overwrite unwanted elements instead of deleting

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for(int x : nums) {
            if(x != val) {
                nums[k++] = x;
            }
        }

        return k;
    }
};

/*
-------------------------------------
🧩 Problem: Find Minimum in Rotated Sorted Array
📂 Category: Binary Search (Rotated Arrays)
🧠 Concept: Minimum lies in unsorted half

⚡ Approach:
- Compare mid with right element
- If nums[mid] > nums[right]:
    → minimum lies in right half
- Else:
    → minimum lies in left half (including mid)

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Sorted half can be discarded safely

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            int mid = left + (right - left) / 2;

            // Minimum lies in right half
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Minimum lies in left half (including mid)
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};

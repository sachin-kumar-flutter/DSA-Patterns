/*
-------------------------------------
🧩 Problem: Binary Search
📂 Category: Binary Search (Foundation)
🧠 Concept: Search in sorted array

⚡ Approach:
- Maintain search space [left, right]
- Compare middle element with target
- Eliminate half of the array each step

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Divide search space by half repeatedly

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] > target) {
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

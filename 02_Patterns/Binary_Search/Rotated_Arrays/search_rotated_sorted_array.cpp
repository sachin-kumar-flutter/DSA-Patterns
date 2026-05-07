/*
-------------------------------------
🧩 Problem: Search in Rotated Sorted Array
📂 Category: Binary Search (Rotated Arrays)
🧠 Concept: Identify sorted half

⚡ Approach:
- One half is always sorted
- Check which half is sorted
- Decide if target lies inside that half
- Eliminate the other half

⏱️ Time Complexity: O(log n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Use sorted half to discard impossible region

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

            // Left half is sorted
            if(nums[left] <= nums[mid]) {

                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }

                else {
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }

                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

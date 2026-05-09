/*
-------------------------------------
🧩 Problem: Subsets II
📂 Category: Backtracking / Recursion
🧠 Concept: Generate unique subsets

⚡ Approach:
- Sort the array
- Generate subsets recursively
- Skip duplicates at same recursion level

⏱️ Time Complexity: O(2^n * n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Avoid duplicate recursion branches

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        solve(0, nums);

        return ans;
    }

    void solve(int idx, vector<int>& nums) {

        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicates
            if(i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);

            solve(i + 1, nums);

            // Backtrack
            temp.pop_back();
        }
    }
};

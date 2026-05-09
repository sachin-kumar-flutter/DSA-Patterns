/*
-------------------------------------
🧩 Problem: Subsets
📂 Category: Backtracking / Recursion
🧠 Concept: Include / Exclude recursion

⚡ Approach:
- At every index:
    → include current element
    → exclude current element
- Generate all possible subsets recursively

⏱️ Time Complexity: O(2^n * n)
💾 Space Complexity: O(n) recursion stack

🎯 Key Idea:
- Every element has 2 choices:
    take it or skip it

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }

    void solve(int idx,
               vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Base case
        if(idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp, ans);

        // Backtrack
        temp.pop_back();

        // Exclude current element
        solve(idx + 1, nums, temp, ans);
    }
};

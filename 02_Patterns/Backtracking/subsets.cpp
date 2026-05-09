/*
-------------------------------------
🧩 Problem: Subsets
📂 Category: Backtracking / Recursion
🧠 Concept: Generate all subsets using recursion

⚡ Approach:
- Start from current index
- Add current subset to answer
- Try every possible next element
- Backtrack after recursion

⏱️ Time Complexity: O(2^n * n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Build subsets incrementally

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

        // Current subset
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {

            temp.push_back(nums[i]);

            solve(i + 1, nums, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }
};

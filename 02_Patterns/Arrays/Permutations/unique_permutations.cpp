/*
-------------------------------------
🧩 Problem: Unique Permutations (with duplicates)
📂 Category: Arrays (Pattern - Permutation / Backtracking)
🧠 Concept: Backtracking + Duplicate Pruning

⚡ Approach:
- Use swap-based backtracking (same as normal permutations)
- At each recursion level, use a set to avoid duplicate choices
- If an element is already used at this level → skip it

Steps:
1. Fix position 'index'
2. Try all elements from index → n-1
3. Skip duplicates using a set
4. Recurse and backtrack

⏱️ Time Complexity: O(n! * n)
💾 Space Complexity: O(n) + O(n) (set per level)

🎯 Key Idea:
- Avoid generating duplicate permutations by pruning choices early

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }

    void solve(vector<int> &nums, vector<vector<int>> &ans, int index) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // tracks elements used at current level

        for(int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if(used.find(nums[i]) != used.end()) continue;

            used.insert(nums[i]);

            swap(nums[i], nums[index]);          // choose
            solve(nums, ans, index + 1);         // explore
            swap(nums[i], nums[index]);          // backtrack
        }
    }
};

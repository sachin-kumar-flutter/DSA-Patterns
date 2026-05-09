/*
-------------------------------------
🧩 Problem: Combination Sum II
📂 Category: Backtracking / Recursion
🧠 Concept: Unique combinations with pruning

⚡ Approach:
- Sort the array
- Generate combinations recursively
- Skip duplicates at same recursion level
- Each element can be used only once

⏱️ Time Complexity: Exponential
💾 Space Complexity: O(target)

🎯 Key Idea:
- Duplicate pruning + target reduction

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates);

        return ans;
    }

    void solve(int idx,
               int target,
               vector<int>& candidates) {

        // Valid combination
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // Invalid path
        if(target < 0) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if(i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Pruning
            if(candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            // Move forward because reuse NOT allowed
            solve(i + 1, target - candidates[i], candidates);

            // Backtrack
            temp.pop_back();
        }
    }
};

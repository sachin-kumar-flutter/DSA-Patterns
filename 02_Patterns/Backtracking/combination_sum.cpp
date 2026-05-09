/*
-------------------------------------
🧩 Problem: Combination Sum
📂 Category: Backtracking / Recursion
🧠 Concept: Choose again vs move forward

⚡ Approach:
- Try every candidate starting from idx
- Include current element
- Reduce remaining target
- Reuse same element by staying at same index

⏱️ Time Complexity: Exponential
💾 Space Complexity: O(target)

🎯 Key Idea:
- Same element can be chosen multiple times

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        solve(0, target, candidates);

        return ans;
    }

    void solve(int idx,
               int target,
               vector<int>& candidates) {

        // Valid combination found
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // Invalid path
        if(target < 0) {
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {

            temp.push_back(candidates[i]);

            // Stay at i because reuse is allowed
            solve(i, target - candidates[i], candidates);

            // Backtrack
            temp.pop_back();
        }
    }
};

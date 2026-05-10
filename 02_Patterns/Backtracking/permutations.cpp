/*
-------------------------------------
🧩 Problem: Permutations
📂 Category: Backtracking / Recursion
🧠 Concept: Generate all possible arrangements

⚡ Approach:
- Try placing every unused element
- Mark element as visited
- Recurse for next position
- Backtrack after recursion

⏱️ Time Complexity: O(n! * n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Every recursion level fixes one position

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<bool> visited(n, false);

        solve(visited, nums);

        return ans;
    }

    void solve(vector<bool>& visited,
               vector<int>& nums) {

        // Complete permutation formed
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Skip already used elements
            if(visited[i]) {
                continue;
            }

            visited[i] = true;
            temp.push_back(nums[i]);

            solve(visited, nums);

            // Backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
};

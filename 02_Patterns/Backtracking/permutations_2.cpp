/*
-------------------------------------
🧩 Problem: Permutations II
📂 Category: Backtracking / Recursion
🧠 Concept: Unique permutations with pruning

⚡ Approach:
- Sort the array
- Use visited array to track used elements
- Skip duplicate choices at same recursion level
- Generate unique permutations recursively

⏱️ Time Complexity: O(n! * n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Avoid duplicate permutation branches

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<bool> visited(nums.size(), false);

        solve(nums, visited);

        return ans;
    }

    void solve(vector<int>& nums,
               vector<bool>& visited) {

        // Complete permutation formed
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Skip used elements
            if(visited[i]) {
                continue;
            }

            // Skip duplicates
            if(i > 0 &&
               nums[i] == nums[i - 1] &&
               !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            temp.push_back(nums[i]);

            solve(nums, visited);

            // Backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
};

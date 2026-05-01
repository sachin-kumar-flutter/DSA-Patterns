/*
-------------------------------------
🧩 Problem: Generate All Permutations
📂 Category: Arrays (Pattern - Permutation / Backtracking)
🧠 Concept: Recursion + Backtracking (Swap-based)

⚡ Approach:
- Fix each element at current index
- Recursively generate permutations for remaining positions
- Backtrack by swapping back

Steps:
1. Start from index = 0
2. For every index, swap it with all possible positions
3. Recurse for next index
4. Backtrack (restore original array)

⏱️ Time Complexity: O(n! * n)
💾 Space Complexity: O(n) (recursion stack)

🎯 Key Idea:
- Generate permutations by fixing one position at a time

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }

    void solve(vector<int> &nums, vector<vector<int>> &ans, int index) {
        // Base case: one permutation ready
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);          // choose
            solve(nums, ans, index + 1);         // explore
            swap(nums[i], nums[index]);          // backtrack
        }
    }
};

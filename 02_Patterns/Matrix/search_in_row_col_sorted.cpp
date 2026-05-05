/*
-------------------------------------
🧩 Problem: Search in 2D Matrix II
📂 Category: Matrix (Pattern - Greedy Search)
🧠 Concept: Start from top-right corner

⚡ Approach:
- Start at top-right element
- If current > target → move left
- If current < target → move down
- Repeat until found or out of bounds

⏱️ Time Complexity: O(m + n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Each step eliminates one row or one column

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0, j = cols - 1;

        while(i < rows && j >= 0) {

            if(matrix[i][j] == target) return true;

            else if(matrix[i][j] > target) j--;   // eliminate column

            else i++;                             // eliminate row
        }

        return false;
    }
};

/*
-------------------------------------
🧩 Problem: Rotate Image (90° Clockwise)
📂 Category: Matrix (Pattern)
🧠 Concept: Transpose + Reverse

⚡ Approach:
1. Transpose the matrix
   → swap(matrix[i][j], matrix[j][i])
2. Reverse each row

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Rotation = Transpose + Reverse rows

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

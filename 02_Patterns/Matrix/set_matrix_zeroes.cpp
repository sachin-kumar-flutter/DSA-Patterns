/*
-------------------------------------
🧩 Problem: Set Matrix Zeroes
📂 Category: Matrix (Pattern - In-place Marking)
🧠 Concept: Use first row & column as markers

⚡ Approach:
1. Check if first row/column initially contain zero
2. Use first row & column to mark zero rows/columns
3. Update matrix based on markers
4. Finally update first row/column if needed

⏱️ Time Complexity: O(m * n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Reuse matrix itself as storage to avoid extra space

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false, firstColZero = false;

        // Step 1: Check first column
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) firstColZero = true;
        }

        // Step 2: Check first row
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) firstRowZero = true;
        }

        // Step 3: Mark rows & columns
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Apply marks
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Handle first row
        if(firstRowZero) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Handle first column
        if(firstColZero) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

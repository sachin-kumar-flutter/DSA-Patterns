/*
-------------------------------------
🧩 Problem: Diagonal Traversal (Anti-diagonals)
📂 Category: Matrix (Pattern - Traversal)
🧠 Concept: Traverse diagonals starting from first row & last column

⚡ Approach:
1. Traverse diagonals starting from first row
2. Then traverse diagonals starting from last column
3. Move along (row++, col--)

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(n^2) (output)

🎯 Key Idea:
- Each diagonal has constant (row + col)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> ans;

        // Diagonals starting from first row
        for(int col = 0; col < n; col++) {
            int row = 0, j = col;
            while(row < n && j >= 0) {
                ans.push_back(mat[row][j]);
                row++; j--;
            }
        }

        // Diagonals starting from last column (excluding first row)
        for(int row = 1; row < n; row++) {
            int i = row, col = n - 1;
            while(i < n && col >= 0) {
                ans.push_back(mat[i][col]);
                i++; col--;
            }
        }

        return ans;
    }
};

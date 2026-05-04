/*
-------------------------------------
🧩 Problem: Sort Matrix Column-wise
📂 Category: Matrix (Pattern - Transformation)
🧠 Concept: Transpose + Row Sorting

⚡ Approach:
1. Transpose the matrix
2. Sort each row (original columns)
3. Transpose back

⏱️ Time Complexity: O(n * m log m)
💾 Space Complexity: O(n * m)

🎯 Key Idea:
- Column operations can be converted into row operations using transpose

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> transpose(const vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> tr(m, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tr[j][i] = mat[i][j];
            }
        }
        return tr;
    }

    vector<vector<int>> sortColumns(vector<vector<int>> mat) {

        // Step 1: Transpose
        vector<vector<int>> tr = transpose(mat);

        // Step 2: Sort rows (i.e., original columns)
        for(auto &row : tr) {
            sort(row.begin(), row.end());
        }

        // Step 3: Transpose back
        return transpose(tr);
    }
};

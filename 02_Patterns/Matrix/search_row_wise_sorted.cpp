/*
-------------------------------------
🧩 Problem: Search in Row-wise Sorted Matrix
📂 Category: Matrix (Pattern - Binary Search)
🧠 Concept: Row selection + Binary search

⚡ Approach:
- Iterate over rows
- If target lies in row range:
    → Apply binary search on that row

⏱️ Time Complexity: O(m log n)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Narrow down candidate row before binary search

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {

            // Check if x can exist in this row
            if(x >= mat[i][0] && x <= mat[i][n - 1]) {

                int left = 0, right = n - 1;

                while(left <= right) {
                    int mid = left + (right - left) / 2;

                    if(mat[i][mid] == x) return true;
                    else if(mat[i][mid] < x) left = mid + 1;
                    else right = mid - 1;
                }
            }
        }

        return false;
    }
};

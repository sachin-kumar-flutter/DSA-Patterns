/*
-------------------------------------
🧩 Problem: Search in 2D Matrix
📂 Category: Matrix (Pattern - Binary Search)
🧠 Concept: Treat matrix as sorted 1D array

⚡ Approach:
- Apply binary search on range [0, m*n - 1]
- Convert index → (row, col):
    → row = mid / cols
    → col = mid % cols

⏱️ Time Complexity: O(log(m*n))
💾 Space Complexity: O(1)

🎯 Key Idea:
- Flatten matrix logically without extra space

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0, end = rows * cols - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            int r = mid / cols;
            int c = mid % cols;

            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};

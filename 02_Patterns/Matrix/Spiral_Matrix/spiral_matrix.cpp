/*
-------------------------------------
🧩 Problem: Spiral Matrix
📂 Category: Matrix (Pattern - Boundary Traversal)
🧠 Concept: Layer-by-layer traversal

⚡ Approach:
- Maintain four boundaries:
    → top, bottom, left, right
- Traverse in 4 directions:
    → left → right (top row)
    → top → bottom (right column)
    → right → left (bottom row)
    → bottom → top (left column)
- Shrink boundaries after each step

⏱️ Time Complexity: O(m * n)
💾 Space Complexity: O(1) (excluding output)

🎯 Key Idea:
- Traverse matrix in layers (like peeling an onion)

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while(left <= right && top <= bottom) {

            // Top row
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Right column
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Left column
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

/*
-------------------------------------
🧩 Problem: K-th Element in Spiral Traversal
📂 Category: Matrix (Pattern - Spiral Variation)
🧠 Concept: Boundary Traversal + Early Exit

⚡ Approach:
- Traverse matrix in spiral order
- Keep a counter
- Return element when count == k

⏱️ Time Complexity: O(R * C)
💾 Space Complexity: O(1)

🎯 Key Idea:
- Stop traversal early once k-th element is reached

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findK(vector<vector<int>> &mat, int k) {

        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;

        int count = 0;

        while(left <= right && top <= bottom) {

            // Top row
            for(int i = left; i <= right; i++) {
                if(++count == k) return mat[top][i];
            }
            top++;

            // Right column
            for(int i = top; i <= bottom; i++) {
                if(++count == k) return mat[i][right];
            }
            right--;

            // Bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    if(++count == k) return mat[bottom][i];
                }
                bottom--;
            }

            // Left column
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    if(++count == k) return mat[i][left];
                }
                left++;
            }
        }

        return -1; // invalid k
    }
};

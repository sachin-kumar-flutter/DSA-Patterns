/*
-------------------------------------
🧩 Problem: Rotate the Box
📂 Category: Matrix (Simulation + Rotation)
🧠 Concept: Gravity simulation + transpose

⚡ Approach:
1. Simulate gravity row-wise:
   - Stones '#' fall right until obstacle '*' or boundary
2. Rotate the matrix 90° clockwise

⏱️ Time Complexity: O(m * n)
💾 Space Complexity: O(m * n)

🎯 Key Idea:
- First simulate physics, then apply transformation

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity (rightwards)
        for(int i = 0; i < m; i++) {
            int empty = n - 1;

            for(int j = n - 1; j >= 0; j--) {
                if(boxGrid[i][j] == '*') {
                    empty = j - 1;
                } 
                else if(boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: Rotate 90° clockwise
        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};

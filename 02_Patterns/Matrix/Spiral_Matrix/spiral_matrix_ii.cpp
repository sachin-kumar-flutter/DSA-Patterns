/*
-------------------------------------
🧩 Problem: Spiral Matrix II (Generate Matrix)
📂 Category: Matrix (Pattern - Boundary Traversal)
🧠 Concept: Spiral Filling

⚡ Approach:
- Maintain 4 boundaries:
    → top, bottom, left, right
- Fill numbers from 1 → n² in spiral order
- Shrink boundaries after each layer

⏱️ Time Complexity: O(n^2)
💾 Space Complexity: O(n^2)

🎯 Key Idea:
- Same as spiral traversal, but filling instead of reading

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int count = 1;

        while(left <= right && top <= bottom) {

            for(int i = left; i <= right; i++)
                ans[top][i] = count++;
            top++;

            for(int i = top; i <= bottom; i++)
                ans[i][right] = count++;
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    ans[bottom][i] = count++;
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    ans[i][left] = count++;
                left++;
            }
        }

        return ans;
    }
};

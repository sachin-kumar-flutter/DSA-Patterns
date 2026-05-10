/*
-------------------------------------
🧩 Problem: N-Queens
📂 Category: Advanced Backtracking
🧠 Concept: Constraint-based board search

⚡ Approach:
- Place one queen per row
- Track unsafe columns and diagonals
- Use hashing for O(1) safety checks
- Backtrack after exploring each position

⏱️ Time Complexity: Exponential
💾 Space Complexity: O(n)

🎯 Key Idea:
- Efficient pruning using diagonal hashing

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {

        string row(n, '.');

        vector<string> board(n, row);

        vector<bool> column(n, false);

        // Diagonal hashing
        vector<bool> leftDiag(2 * n, false);
        vector<bool> rightDiag(2 * n, false);

        nQueens(0, n, board, column, leftDiag, rightDiag);

        return ans;
    }

    void nQueens(int row,
                 int n,
                 vector<string>& board,
                 vector<bool>& column,
                 vector<bool>& leftDiag,
                 vector<bool>& rightDiag) {

        // Valid configuration found
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            // Unsafe position
            if(column[col] ||
               leftDiag[row - col + n] ||
               rightDiag[row + col]) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';

            column[col] = true;
            leftDiag[row - col + n] = true;
            rightDiag[row + col] = true;

            nQueens(row + 1,
                    n,
                    board,
                    column,
                    leftDiag,
                    rightDiag);

            // Backtrack
            board[row][col] = '.';

            column[col] = false;
            leftDiag[row - col + n] = false;
            rightDiag[row + col] = false;
        }
    }
};

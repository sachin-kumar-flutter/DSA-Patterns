/*
-------------------------------------
🧩 Problem: Word Search
📂 Category: Advanced Backtracking
🧠 Concept: Grid DFS + Backtracking

⚡ Approach:
- Start DFS from every cell
- Match characters recursively
- Mark visited cells temporarily
- Backtrack after exploration

⏱️ Time Complexity: O(m * n * 4^L)
💾 Space Complexity: O(L)

🎯 Key Idea:
- Explore paths while avoiding revisiting cells

-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int row = 0; row < m; row++) {

            for(int col = 0; col < n; col++) {

                if(solve(row, col, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool solve(int row,
               int col,
               int idx,
               vector<vector<char>>& board,
               string& word) {

        // Entire word matched
        if(idx == word.size()) {
            return true;
        }

        // Invalid cell or mismatch
        if(row < 0 ||
           col < 0 ||
           row >= board.size() ||
           col >= board[0].size() ||
           board[row][col] != word[idx]) {

            return false;
        }

        char ch = board[row][col];

        // Mark visited
        board[row][col] = '#';

        bool found =
            solve(row - 1, col, idx + 1, board, word) ||
            solve(row + 1, col, idx + 1, board, word) ||
            solve(row, col - 1, idx + 1, board, word) ||
            solve(row, col + 1, idx + 1, board, word);

        // Backtrack
        board[row][col] = ch;

        return found;
    }
};

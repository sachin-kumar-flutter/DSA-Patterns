/*
-------------------------------------
🧩 Problem: 01 Matrix
📂 Category: Graph / Multi-Source BFS
🧠 Concept:
- Multi-source BFS
- Shortest distance in grid

⚡ Approach:
- Push all 0 cells into queue
- Distance of every 0 is 0
- Expand simultaneously from all 0s
- First time reaching a cell gives
  shortest distance to nearest 0

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)

🎯 Key Idea:
- Treat all 0 cells as BFS sources

-------------------------------------
*/

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> distance(rows,vector<int>(cols, INT_MAX));
        queue<pair<int, int>> bfsQueue;

        // All 0s become BFS sources
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(mat[row][col] == 0) {
                    distance[row][col] = 0;
                    bfsQueue.push({row, col});
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};

        while(!bfsQueue.empty()) {

            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();

            for(auto& direction : directions) {

                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && distance[newRow][newCol] == INT_MAX) {

                    distance[newRow][newCol] = distance[row][col] + 1;
                    bfsQueue.push({newRow, newCol});
                }
            }
        }

        return distance;
    }
};

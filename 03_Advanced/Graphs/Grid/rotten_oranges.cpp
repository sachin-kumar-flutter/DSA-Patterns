/*
-------------------------------------
🧩 Problem: Rotting Oranges
📂 Category: Graph / Multi-Source BFS
🧠 Concept:
- Multi-source BFS
- Level-order traversal
- Grid graph traversal

⚡ Approach:
- Push all rotten oranges into queue
- Count fresh oranges
- Perform BFS simultaneously
  from all rotten oranges
- Each BFS level represents
  one minute of spread

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)

🎯 Key Idea:
- Start BFS from ALL rotten oranges
  at the same time

-------------------------------------
*/

class Solution {
public:

    int orangesRot(vector<vector<int>>& mat) {

        int freshOranges = 0;
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int, int>> bfsQueue;

        // Count fresh oranges and
        // collect all rotten oranges
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(mat[row][col] == 1) freshOranges++;
                else if(mat[row][col] == 2) bfsQueue.push({row, col});
            }
        }

        // No fresh oranges present
        if(freshOranges == 0) return 0;
        int minutes = 0;

        vector<pair<int, int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        /*
        BFS Level Traversal

        Each level represents
        one minute of rotting
        */
        while(!bfsQueue.empty() && freshOranges > 0) {

            int currentLevelSize = bfsQueue.size();
            minutes++;

            for(int i = 0;i < currentLevelSize;i++) {

                auto [row, col] = bfsQueue.front();
                bfsQueue.pop();
                // Explore 4 directions
                for(auto& direction : directions) {

                    int newRow = row + direction.first;
                    int newCol = col + direction.second;

                    // Fresh orange found
                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && mat[newRow][newCol] == 1) {

                        // Rot it
                        mat[newRow][newCol] = 2;
                        freshOranges--;

                        // Add for next minute
                        bfsQueue.push({newRow, newCol});
                    }
                }
            }
        }

        // If fresh oranges remain,
        // impossible to rot all
        return freshOranges == 0 ? minutes : -1;
    }
};

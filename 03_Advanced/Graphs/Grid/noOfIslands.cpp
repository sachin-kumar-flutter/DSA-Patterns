/*
-------------------------------------
🧩 Problem: Number of Islands
📂 Category: Graph / Grid BFS
🧠 Concept:
- Connected Components
- Breadth First Search
- Grid Traversal

⚡ Approach:
- Traverse every cell
- When an unvisited land ('1')
  is found, a new island starts
- Perform BFS to visit the entire
  connected component
- Mark visited land as water ('0')

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)

🎯 Key Idea:
- One BFS = One Complete Island

-------------------------------------
*/

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        vector<pair<int,int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                // New island found
                if(grid[row][col] == '1') {
                    islands++;
                    queue<pair<int,int>> bfsQueue;
                    bfsQueue.push({row, col});
                    // Mark starting cell visited
                    grid[row][col] = '0';

                    while(!bfsQueue.empty()) {

                        auto [x, y] = bfsQueue.front();
                        bfsQueue.pop();

                        // Explore 4 directions
                        for(auto& direction : directions) {

                            int newRow = x + direction.first;
                            int newCol = y + direction.second;

                            // Valid unvisited land
                            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == '1') {

                                // Mark visited
                                grid[newRow][newCol] = '0';
                                bfsQueue.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

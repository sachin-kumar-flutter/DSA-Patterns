/*
-------------------------------------
🧩 Problem: Number of Islands
📂 Category: Graph / Grid DFS
🧠 Concept:
- Connected Components
- Depth First Search
- Grid Traversal

⚡ Approach:
- Traverse every cell in the grid
- When an unvisited land cell ('1')
  is found, a new island is discovered
- Run DFS to visit the entire island
- Mark visited land as water ('0')

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)
   (Recursive call stack)

🎯 Key Idea:
- One DFS call explores
  one complete island

-------------------------------------
*/

class Solution {
public:

    int rows, cols;

    int numIslands(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;

        // Traverse every cell
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                // New island found
                if(grid[row][col] == '1') {
                    islands++;
                    dfs(grid, row, col);
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {

        // Out of bounds OR water OR
        // already visited land
        if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1') return;
        // Mark current land visited
        grid[row][col] = '0';

        // Explore all 4 directions
        dfs(grid, row + 1, col); // Down
        dfs(grid, row - 1, col); // Up
        dfs(grid, row, col + 1); // Right
        dfs(grid, row, col - 1); // Left
    }
};

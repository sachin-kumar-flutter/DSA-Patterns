/*
-------------------------------------
🧩 Problem: Flood Fill
📂 Category: Graph / Grid BFS
🧠 Concept:
- Breadth First Search on a matrix
- Connected component traversal

⚡ Approach:
- Start from given cell
- Store original color
- BFS over all connected cells
  having the same color
- Recolor while traversing

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)

Where:
- m = rows
- n = columns

🎯 Key Idea:
- Treat each cell as a graph node
- Traverse only cells with the same color

-------------------------------------
*/

class Solution {
public:

    vector<vector<int>> floodFill( vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // No change required
        if(originalColor == color) return image;

        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({sr, sc});
        image[sr][sc] = color;

        vector<pair<int,int>> directions = {{-1, 0},{0, 1},{1, 0},{0, -1}};

        while(!bfsQueue.empty()) {

            auto [row, col] = bfsQueue.front();
            bfsQueue.pop();

            for(auto& direction : directions) {

                int newRow = row + direction.first;
                int newCol = col + direction.second;
                if(newRows>=0 && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == originalColor) {

                    image[newRow][newCol] = color;
                    bfsQueue.push({newRow, newCol});
                }
            }
        }

        return image;
    }
};

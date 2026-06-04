/*
-------------------------------------
🧩 Problem: Flood Fill
📂 Category: Graph / Grid DFS
🧠 Concept:
- Depth First Search
- Connected Components
- Grid Traversal

⚡ Approach:
- Start DFS from source cell
- Replace original color
  with target color
- Recursively visit all
  connected cells having
  the original color

⏱️ Time Complexity: O(m × n)
💾 Space Complexity: O(m × n)
   (Recursive call stack)

🎯 Key Idea:
- DFS explores the entire
  connected component before
  returning

-------------------------------------
*/

class Solution {
public:
    int rows, cols;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor = image[sr][sc];
        // No change required
        if(originalColor == color) return image;

        rows = image.size();
        cols = image[0].size();
        dfs(image, sr, sc, color, originalColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int originalColor) {
        // Out of bounds OR
        // different color
        if(row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != originalColor) return;

        // Recolor current cell
        image[row][col] = newColor;
        // Explore all 4 directions
        dfs(image, row + 1, col, newColor, originalColor); // Down
        dfs(image, row - 1, col, newColor, originalColor); // Up
        dfs(image, row, col + 1, newColor, originalColor); // Right
        dfs(image, row, col - 1, newColor, originalColor); // Left
    }
};

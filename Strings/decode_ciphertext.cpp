/*
-----------------------------------------------
Problem: Decode the Slanted Ciphertext
-----------------------------------------------

💡 Idea:
- The encoded text is written row-wise into a grid of size (rows x cols),
  where cols = encodedText.size() / rows.
- The original message is formed by reading the grid diagonally:
    start from each column in the first row,
    then move (row+1, col+1) until out of bounds.
- Finally, remove trailing spaces from the result.

🧠 Key Insight:
- Encoding → row-wise fill
- Decoding → diagonal traversal

⏱ Time Complexity:
- Filling grid: O(n)
- Traversing diagonals: O(n)
- Removing trailing spaces: O(n)
👉 Overall: O(n)

💾 Space Complexity:
- Grid storage: O(n)
👉 Overall: O(n)

-----------------------------------------------
*/

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        // Calculate number of columns
        int col = encodedText.size() / rows;

        // Pointer to traverse encoded string
        int e = 0;

        // Create grid to store characters
        vector<vector<int>> grid(rows, vector<int>(col));

        // Fill the grid row-wise
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                grid[i][j] = encodedText[e++];
            }
        }

        string ans;

        // Traverse diagonally starting from each column
        for(int j = 0; j < col; j++){
            int c = j;
            int r = 0;

            while(c < col && r < rows){
                ans += grid[r++][c++];
            }
        }

        // Remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};

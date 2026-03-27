class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        // Create an 8x8 chess board and mark positions of queens
        vector<vector<bool>> board(8, vector<bool>(8, false));
        vector<vector<int>> ans;

        for (auto &q : queens) {
            board[q[0]][q[1]] = true;
        }

        int x = king[0], y = king[1];

        // All 8 possible directions from the king
        vector<pair<int,int>> directions = {
            {0,1},   // right
            {0,-1},  // left
            {1,0},   // down
            {-1,0},  // up
            {1,1},   // south-east
            {1,-1},  // south-west
            {-1,1},  // north-east
            {-1,-1}  // north-west
        };

        // Traverse in each direction
        for (auto &dir : directions) {
            int dx = dir.first;
            int dy = dir.second;

            int nx = x + dx;
            int ny = y + dy;

            // Move step-by-step until out of bounds
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                
                // If a queen is found, it can attack the king
                if (board[nx][ny]) {
                    ans.push_back({nx, ny});
                    break; // Stop in this direction
                }

                nx += dx;
                ny += dy;
            }
        }

        return ans;
    }
};

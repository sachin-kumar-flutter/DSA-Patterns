class Solution {
  public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {

        // Convert 1-based indexing to 0-based indexing
        KnightPos[0]--; KnightPos[1]--;
        TargetPos[0]--; TargetPos[1]--;

        // Knight is already at the target
        if(KnightPos == TargetPos) return 0;

        // Visited matrix to avoid revisiting cells
        vector<vector<bool>> grid(N, vector<bool>(N, true));

        // All 8 possible knight moves
        vector<pair<int,int>> dir = {
            {2,1}, {2,-1}, {-2,1}, {-2,-1},
            {1,2}, {1,-2}, {-1,2}, {-1,-2}
        };

        queue<pair<int,int>> q;

        // Start BFS from knight's position
        q.push({KnightPos[0], KnightPos[1]});
        grid[KnightPos[0]][KnightPos[1]] = false;

        int steps = 0;

        // BFS guarantees first time reaching target = minimum moves
        while(!q.empty()) {

            int size = q.size();
            steps++;

            // Process one BFS level at a time
            while(size--) {

                auto [x, y] = q.front();
                q.pop();

                for(auto &d : dir) {

                    int nx = x + d.first;
                    int ny = y + d.second;

                    // Ignore positions outside the chessboard
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;

                    // First time reaching target => shortest path
                    if(nx == TargetPos[0] && ny == TargetPos[1])
                        return steps;

                    // Visit unvisited cells
                    if(grid[nx][ny]) {
                        grid[nx][ny] = false;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};

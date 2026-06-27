class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>> q;

        // Step 1: find all initially rotten oranges (multi-source BFS starting points)
        // and count total fresh oranges that need to be infected
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int minutes = 0;

        // Step 2: BFS level by level — each level = 1 minute passing
        while (!q.empty()) {
            int size = q.size(); // number of rotten oranges at this "minute"
            if (fresh == 0) break; // all fresh oranges infected, no need to count further minutes

            minutes++;

            // process all rotten oranges from the current minute together,
            // so the next minute only contains newly infected ones
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    // infect neighbor if it's a valid, fresh orange
                    if (nx < rows && nx >= 0 && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // if any fresh oranges remain unreachable, return -1; otherwise return minutes taken
        return fresh ? -1 : minutes;
    }
};

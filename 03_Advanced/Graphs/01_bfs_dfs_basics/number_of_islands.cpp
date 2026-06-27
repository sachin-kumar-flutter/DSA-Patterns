// LeetCode 200 - Number of Islands
// Approach 1: BFS (iterative, using queue)
// Time: O(rows * cols), Space: O(min(rows, cols)) for queue in worst case

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        // Direction vectors for 4-directional movement: right, down, left, up
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Found an unvisited land cell -> start of a new island
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0'; // mark visited immediately to avoid re-processing

                    queue<pair<int,int>> q;
                    q.push({i, j});

                    // BFS: flood-fill this entire island, marking all connected land as visited
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            // Visit neighbor only if within bounds and still land
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0'; // mark visited before pushing (avoids duplicate enqueues)
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

// Approach 2: DFS (recursive, using call stack)
// Time: O(rows * cols), Space: O(rows * cols) worst case (recursion stack on a fully-land grid)

class Solution {
public:
    int rows, cols;

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Found an unvisited land cell -> start of a new island
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid); // sink the entire island in one recursive sweep
                }
            }
        }

        return islands;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        // Base case: out of bounds or already water/visited -> stop recursion
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') return;

        grid[i][j] = '0'; // mark visited (sink the land)

        // Explore all 4 directions
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};

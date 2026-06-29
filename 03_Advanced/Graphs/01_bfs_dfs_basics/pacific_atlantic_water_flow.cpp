// LeetCode 417 - Pacific Atlantic Water Flow
//
// Problem: Given a grid of heights, find all cells from which water can flow
// to BOTH the Pacific (top + left border) and Atlantic (bottom + right border) oceans.
// Water can only flow from a cell to a neighbor with height <= current cell's height.
//
// Key insight: instead of checking "can water flow FROM this cell TO the ocean"
// (which would require running a traversal from every single cell - O((rows*cols)^2)),
// we reverse the problem: start BFS/DFS FROM the ocean borders INWARD, and move to a
// neighbor only if neighbor's height >= current height (i.e., water could have flowed
// from that neighbor down into the current cell). This brings it down to O(rows*cols).

// ============================================================
// Approach 1: BFS (multi-source, one BFS per ocean)
// Time: O(rows * cols), Space: O(rows * cols) for visited arrays + queue
// ============================================================

class SolutionBFS {
public:
    int rows, cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int,int>> pq, aq; // separate queues for each ocean's BFS

        // Pacific touches the top row and the left column
        for (int i = 0; i < cols; i++) pq.push({0, i});
        for (int i = 0; i < rows; i++) pq.push({i, 0});

        // Atlantic touches the bottom row and the right column
        for (int i = 0; i < rows; i++) aq.push({i, cols - 1});
        for (int i = 0; i < cols; i++) aq.push({rows - 1, i});

        bfs(pq, pacific, heights);
        bfs(aq, atlantic, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // a cell qualifies only if water can reach BOTH oceans from it
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &visited, vector<vector<int>> &heights) {
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        // mark all initial border cells visited upfront, before processing starts
        queue<pair<int,int>> temp = q;
        while (!temp.empty()) {
            auto [x, y] = temp.front();
            temp.pop();
            visited[x][y] = true;
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                // move to neighbor only if: in bounds, NOT already visited,
                // and neighbor's height >= current height
                // (water could have flowed FROM neighbor INTO current cell)
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = true; // mark visited immediately on push, avoids duplicate enqueues
                    q.push({nx, ny});
                }
            }
        }
    }
};

// ============================================================
// Approach 2: DFS (recursive, one DFS call per border cell)
// Time: O(rows * cols), Space: O(rows * cols) worst case (recursion stack)
// ============================================================

class SolutionDFS {
public:
    int rows, cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific: start DFS from every cell on the top row and left column
        for (int j = 0; j < cols; j++) dfs(0, j, pacific, heights);
        for (int i = 0; i < rows; i++) dfs(i, 0, pacific, heights);

        // Atlantic: start DFS from every cell on the bottom row and right column
        for (int j = 0; j < cols; j++) dfs(rows - 1, j, atlantic, heights);
        for (int i = 0; i < rows; i++) dfs(i, cols - 1, atlantic, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &heights) {
        // already visited from this ocean -> stop (avoids re-exploring and infinite loops on flat areas)
        if (visited[x][y]) return;

        visited[x][y] = true;

        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for (auto &d : dir) {
            int nx = x + d.first;
            int ny = y + d.second;

            // recurse into neighbor only if: in bounds, not visited,
            // and neighbor's height >= current height (uphill-or-equal from the ocean inward)
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, visited, heights);
            }
        }
    }
};

/*
NOTES (for revision):

1. This is a "reverse traversal" pattern - instead of checking outward flow from
   every cell (expensive), flood-fill INWARD from both oceans simultaneously.

2. The visited check happening BEFORE the height comparison is what prevents infinite
   loops on flat regions (equal heights) - this is the most common bug in both BFS and DFS
   versions of this problem.

3. BFS vs DFS here: functionally identical results, but DFS is initiated once PER
   border cell (multiple separate calls), while BFS seeds ALL border cells into one
   queue upfront (multi-source BFS in a single pass). Both are O(rows*cols) since each
   cell is visited at most once per ocean.

4. DFS risk: on a very large grid that's one giant connected region, the recursion
   depth can approach rows*cols, risking a stack overflow. BFS avoids this since it's
   iterative.

5. Final answer = intersection of cells reachable from Pacific AND Atlantic (logical AND
   of the two visited grids), NOT a union.
*/

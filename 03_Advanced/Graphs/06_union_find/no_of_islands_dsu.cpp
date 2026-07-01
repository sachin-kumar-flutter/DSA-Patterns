// LeetCode 200 - Number of Islands (Union-Find approach)
//
// NOTE: BFS and DFS solutions for this problem are in:
// 01_BFS_DFS_Basics/200_number_of_islands.cpp
//
// This file covers the Union-Find approach - a fundamentally different
// strategy included here to demonstrate DSU applied to grid problems.
//
// Problem: Count the number of islands (connected components of '1's) in a grid.
//
// Approach: treat each '1' cell as a node. Start with islands = total '1' count.
// For every adjacent pair of '1' cells, unite them - if they were in different
// components (unite returns true), decrement islands by 1.
// Final islands count = number of remaining disjoint components.
//
// Key trick: flatten 2D grid index to 1D for DSU -> node id = i*cols + j
// Only check RIGHT and DOWN neighbors (not all 4) to avoid double-processing
// the same pair twice.

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // already same component
        if (size[px] < size[py]) swap(px, py); // union by size
        parent[py] = px;
        size[px] += size[py];
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        DSU dsu(rows * cols);
        int islands = 0;

        // only right and down - avoids re-processing the same pair twice
        vector<pair<int,int>> dir = {{0,1}, {1,0}};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++; // assume every '1' is its own island initially

                    for (auto d : dir) {
                        int nx = d.first + i;
                        int ny = d.second + j;

                        // merge with neighbor if it's also land
                        // if they were separate components, one island merges -> decrement
                        if (nx < rows && ny < cols && grid[nx][ny] == '1') {
                            if (dsu.unite(i * cols + j, nx * cols + ny)) islands--;
                        }
                    }
                }
            }
        }

        return islands;
    }
};

/*
NOTES (for revision):

1. BFS/DFS vs Union-Find for this problem:
   - BFS/DFS: O(rows*cols), modifies the grid (marks visited as '0')
   - Union-Find: O(rows*cols * α(n)) ≈ O(rows*cols), does NOT modify the grid
   Union-Find is the better pick when you can't modify the input grid, or when
   islands are being added dynamically (online queries - BFS/DFS can't handle that).

2. The "only check right and down" optimization avoids checking all 4 directions
   and undoing the double-counting - since you process cells left-to-right,
   top-to-bottom, left and up neighbors are already handled when you were AT them.

3. 2D -> 1D index mapping: i*cols + j. This is the standard trick for applying
   Union-Find to any grid problem. Reverse mapping: row = id/cols, col = id%cols.

4. This is also a good template for "Number of Islands II" (LeetCode 305 - premium),
   where islands are added one at a time via queries - Union-Find handles that
   naturally while BFS/DFS would require re-running from scratch on each addition.
*/

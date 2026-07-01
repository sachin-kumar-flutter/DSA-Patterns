// LeetCode 547 - Number of Provinces
//
// Problem: Given an n x n adjacency MATRIX (isConnected[i][j] = 1 means city i
// and city j are directly connected), find the total number of provinces
// (groups of directly/indirectly connected cities).
//
// This is a connected-components counting problem. Two approaches below.
// DSU is the recommended version here - the question is literally asking
// "how many disjoint groups exist", which is exactly what Union-Find tracks.
//
// NOTE: input is an adjacency MATRIX (not list), so both approaches are O(V^2)
// regardless - there's no asymptotic advantage to either here.

// ============================================================
// Approach 1 (RECOMMENDED): Union-Find (DSU)
// Time: O(V^2 * α(V)) ≈ O(V^2), Space: O(V)
// ============================================================

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // already in the same province
        if (size[px] < size[py]) swap(px, py); // union by size
        parent[py] = px;
        size[px] += size[py];
        return true;
    }
};

class SolutionDSU {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        int provinces = n; // assume every city is its own province initially

        // only scan upper triangle (i < j) - matrix is symmetric,
        // isConnected[i][j] == isConnected[j][i], so no need to check both
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // if connected and in different components -> merge, one less province
                if (isConnected[i][j] == 1) {
                    if (dsu.unite(i, j)) provinces--;
                }
            }
        }

        return provinces;
    }
};

// ============================================================
// Approach 2: BFS
// Time: O(V^2), Space: O(V)
// ============================================================

class SolutionBFS {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++; // new unvisited city = new province found

                // BFS: visit every city reachable from city i
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // must scan entire row - adjacency matrix, not list
                    for (int neighbour = 0; neighbour < n; neighbour++) {
                        if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};

/*
NOTES (for revision):

1. DSU is the natural fit here - the problem is literally "count disjoint groups",
   which is Union-Find's core purpose. BFS works but requires explicit traversal
   to discover what DSU tracks implicitly.

2. Upper triangle optimization in DSU (j starts from i+1, not 0): since
   isConnected is symmetric, each pair (i,j) only needs to be checked once.
   BFS doesn't benefit from this since it must scan full rows anyway.

3. Both are O(V^2) here because the input is an adjacency MATRIX - you must
   examine every cell. If the input were an adjacency LIST, DSU would be
   O(E * α(V)) and BFS would be O(V + E), both faster than O(V^2).

4. This is the same connected-components pattern as Number of Islands (200) -
   islands = provinces, water cells = absent edges. The only structural
   difference is grid (2D) vs adjacency matrix (explicit connections).
*/

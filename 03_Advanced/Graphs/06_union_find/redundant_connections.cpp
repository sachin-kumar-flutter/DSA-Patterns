// LeetCode 684 - Redundant Connection
//
// Problem: Given a graph built by adding edges one by one to n nodes, find the
// first edge that creates a cycle (i.e., the redundant connection).
//
// Core idea: process edges one by one. For each edge, check if the two nodes
// are ALREADY in the same connected component (using Union-Find). If they are,
// this edge is redundant - adding it would create a cycle. Return it immediately.
//
// Union-Find is the natural tool here because it answers the exact question
// we need in near O(1): "are these two nodes already connected?"

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // every node starts as its own component of size 1
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // find with PATH COMPRESSION: flattens the tree by making every node
    // on the path point directly to the root, keeping future finds fast
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // compress path on the way up
        return parent[x];
    }

    // unite with UNION BY SIZE: always attach the smaller component's root
    // under the larger component's root, keeping the tree as flat as possible.
    // returns false if both nodes already share the same root (cycle detected)
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false; // already in the same component -> cycle

        // merge smaller into larger to minimize tree height growth
        if (size[rootX] < size[rootY]) swap(rootX, rootY);
        size[rootX] += size[rootY]; // update the new root's total size
        parent[rootY] = rootX;      // attach smaller tree under the larger root
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1); // 1-indexed nodes (nodes are labeled 1 to n)

        for (auto &e : edges) {
            // if unite returns false, these two nodes were already connected
            // -> this edge creates a cycle -> it's the redundant one
            if (!dsu.unite(e[0], e[1])) return e;
        }

        return {}; // guaranteed to find a redundant edge per problem constraints
    }
};

/*
NOTES (for revision):

1. Union by SIZE vs union by RANK: both give near-O(1) amortized with path
   compression. Size is the better pick because rank (which approximates tree
   height) becomes stale/inaccurate after path compression flattens the tree.
   Size (total node count in component) stays accurate regardless of compression.

2. Path compression + union by size together give O(α(n)) amortized per
   operation where α is the inverse Ackermann function - effectively O(1)
   for all practical input sizes (α(n) ≤ 4 for n up to 10^600).

3. The cycle detection here is elegantly simple: if two nodes to be connected
   already share the same root, the edge between them is redundant. No DFS/BFS
   needed at all.

4. This DSU class is a REUSABLE TEMPLATE - carry it into Kruskal's MST, Number
   of Provinces (547), Number of Connected Components (323), and any problem
   involving dynamic connectivity or grouping.

5. Size array initialized to 1 (not 0 like rank) because every single node
   starts as a valid component of size 1. Rank starts at 0 because tree height
   of a single node is 0. Don't mix these up between implementations.
*/

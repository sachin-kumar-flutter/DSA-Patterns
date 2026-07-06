/*
    GFG - Kruskal's Algorithm (MST)
    --------------------------------
    Problem: Given a weighted undirected graph with V vertices and edges,
    find the sum of weights of edges in the Minimum Spanning Tree (MST).

    Approach: Kruskal's Algorithm (Greedy + DSU)
    ---------------------------------------------
    - Sort all edges by weight in ascending order.
    - Process edges one by one (cheapest first).
    - Add edge to MST only if it doesn't form a cycle.
    - Use DSU (Disjoint Set Union) to efficiently detect cycles.
    - Stop as soon as V-1 edges are added (MST is complete).

    Why Kruskal's here?
    - Graph is given as edge list -> no need to build adjacency list
    - Works better for sparse graphs (few edges)
    - Contrast with Prim's which grows from a single vertex;
      Kruskal's picks globally cheapest safe edge at each step

    Time:  O(E log E) -> dominated by sorting edges
    Space: O(V)       -> DSU parent + size arrays
*/

// --------------------------------------------------
// DSU (Disjoint Set Union) with Path Compression
// and Union by Size
// --------------------------------------------------
class DSU {
public:
    vector<int> parent, size;

    // Initialize each vertex as its own component
    // size[i] = 1 (every component starts with 1 node)
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find root of x's component with PATH COMPRESSION
    // Flattens the tree so future finds are faster (near O(1))
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);   // point directly to root
        return parent[x];
    }

    // Unite components of x and y using UNION BY SIZE
    // Always attach smaller tree under larger tree root
    // Returns true  -> successfully merged (no cycle)
    // Returns false -> already in same component (cycle would form)
    bool unite(int x, int y) {
        int px = find(x);   // root of x's component
        int py = find(y);   // root of y's component

        // same root -> already connected -> adding this edge = cycle
        if (px == py) return false;

        // attach smaller component under larger one
        // keeps tree shallow -> find() stays fast
        if (size[px] < size[py]) swap(px, py);

        parent[py] = px;        // py's tree goes under px
        size[px] += size[py];   // update size of merged component

        return true;
    }
};

// --------------------------------------------------
// Kruskal's MST Solution
// --------------------------------------------------
class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        // Step 1: Sort all edges by weight ascending
        // Kruskal's is greedy -> always pick cheapest edge first
        sort(edges.begin(), edges.end(), [](const vector<int>& a,
                                            const vector<int>& b) {
            return a[2] < b[2];
        });

        int totalEdges = 0;   // edges added to MST so far
        int cost = 0;         // total MST weight

        DSU dsu(V);

        // Step 2: Process edges in sorted order (cheapest first)
        for (auto& e : edges) {
            int u  = e[0];   // edge start vertex
            int v  = e[1];   // edge end vertex
            int wt = e[2];   // edge weight

            // Step 3: Try to add this edge to MST
            // unite() returns true  -> u and v were in different components
            //                      -> safe to add, no cycle formed
            // unite() returns false -> u and v already connected
            //                      -> skip, would form a cycle
            if (dsu.unite(u, v)) {
                cost += wt;
                totalEdges++;
            }

            // Step 4: Early exit — MST always has exactly V-1 edges
            // No need to process remaining edges once MST is complete
            if (totalEdges == V - 1) break;
        }

        return cost;
    }
};

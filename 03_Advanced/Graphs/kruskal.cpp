class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // parent[i] = representative (root) of the set node i belongs to
        // rank[i]   = approximate "height" of the tree rooted at i (used to keep DSU balanced)
        vector<int> parent(V), rank(V, 0);

        // Sort edges by weight (ascending) so we always try the cheapest edge first
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        // Initially, every node is its own parent (each node is its own separate set)
        for (int i = 0; i < V; i++) parent[i] = i;

        int cost = 0;        // total weight of the MST built so far
        int totalEdges = 0;  // number of edges added to the MST so far

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            // Try to unite u and v; only succeeds if they were in different sets
            // (i.e., adding this edge does NOT create a cycle)
            if (unite(u, v, parent, rank)) {
                totalEdges++;
                cost += wt;
            }

            // Optimization: an MST always has exactly V-1 edges.
            // Once we've added that many, we can stop early without scanning remaining edges.
            if (totalEdges == V - 1) return cost;
        }

        return cost;
    }

    // Find the representative (root) of the set containing u, with path compression
    int find(int u, vector<int> &parent) {
        if (u != parent[u]) {
            parent[u] = find(parent[u], parent); // path compression: flatten the tree for future lookups
        }
        return parent[u];
    }

    // Attempt to unite the sets containing u and v
    // Returns false if they're already in the same set (would form a cycle)
    bool unite(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv) return false; // already connected -> adding this edge would create a cycle

        // Union by rank: attach the smaller-rank tree under the larger-rank tree
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;

        if (rank[pu] == rank[pv]) rank[pu]++;

        return true;
    }
};

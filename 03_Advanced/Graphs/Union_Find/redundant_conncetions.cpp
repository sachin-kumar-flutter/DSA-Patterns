class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // parent[i] = representative (parent) of node i
        vector<int> parent(n + 1);

        // rank[i] = approximate height of the tree rooted at i
        vector<int> rank(n + 1, 0);

        // Initially, every node is its own parent
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        // Process each edge
        for (auto &e : edges) {

            // If both nodes already belong to the same set,
            // adding this edge creates a cycle.
            if (!unite(e[0], e[1], parent, rank))
                return e;
        }

        return {};
    }

    // Finds the ultimate parent (representative) of a set.
    // Path Compression flattens the tree, making future
    // find operations almost O(1).
    int find(int u, vector<int> &parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);

        return parent[u];
    }

    // Union by Rank:
    // Attach the shorter tree under the taller tree
    // to keep the overall height minimal.
    bool unite(int x, int y, vector<int> &parent, vector<int> &rank) {

        int px = find(x, parent);
        int py = find(y, parent);

        // Already connected → cycle detected
        if (px == py)
            return false;

        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

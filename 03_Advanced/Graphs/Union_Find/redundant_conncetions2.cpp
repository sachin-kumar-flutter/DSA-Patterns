class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // parent[i] = representative (leader) of the set containing node i
        vector<int> parent(n + 1);

        // size[i] = size of the component whose representative is i
        vector<int> size(n + 1, 1);

        // Initially, every node forms its own set
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        // Process each edge one by one
        for (auto &e : edges) {

            // If both endpoints already belong to the same set,
            // this edge creates a cycle.
            if (!unite(e[0], e[1], parent, size))
                return e;
        }

        return {};
    }

    // Returns the representative of the component.
    // Path Compression makes future queries nearly O(1).
    int find(int u, vector<int> &parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);

        return parent[u];
    }

    // Union by Size:
    // Always attach the smaller component under the larger one.
    bool unite(int x, int y, vector<int> &parent, vector<int> &size) {

        int px = find(x, parent);
        int py = find(y, parent);

        // Already connected -> adding this edge forms a cycle
        if (px == py)
            return false;

        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }

        return true;
    }
};

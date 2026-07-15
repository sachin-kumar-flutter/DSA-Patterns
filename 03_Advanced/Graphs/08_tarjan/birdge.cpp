class Solution {
public:
    int timer = 0;

    vector<vector<int>> criticalConnections(int n,
                         vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++)
            if (disc[i] == -1)
                dfs(i, -1, graph, disc, low, bridges);

        return bridges;
    }

    void dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<int>& disc, vector<int>& low,
             vector<vector<int>>& bridges) {

        disc[node] = low[node] = timer++;
        //  ↑ disc and low both start equal
        //  low will decrease as back edges are found

        for (int neighbour : graph[node]) {

            if (neighbour == parent) continue;
            //  ↑ CRITICAL: don't treat the edge we
            //  came from as a back edge in undirected graph.
            //  Without this, low[node] would always
            //  equal disc[parent] and no bridges found.

            if (disc[neighbour] == -1) {
                // TREE EDGE — go deeper
                dfs(neighbour, node, graph, disc, low, bridges);

                low[node] = min(low[node], low[neighbour]);
                //  ↑ PULL UP: whatever child can reach,
                //  current node can also reach.
                //  This propagates back edge info upward.

                if (low[neighbour] > disc[node])
                    bridges.push_back({node, neighbour});
                //  ↑ BRIDGE CHECK:
                //  child's subtree cannot reach node or above.
                //  This edge is the only connection.
            }
            else {
                // BACK EDGE — found already visited ancestor
                low[node] = min(low[node], disc[neighbour]);
                //  ↑ UPDATE low with ancestor's disc time.
                //  This is what "escapes" a potential bridge.
                //  Note: use disc[neighbour], NOT low[neighbour]
                //  (to avoid cross-edge issues in undirected graphs)
            }
        }
    }
};

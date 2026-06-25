class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list representation of the graph
        // graph[u] = list of {neighbor, edge_weight}
        vector<vector<pair<int,int>>> graph(V);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]}); // undirected graph, add both directions
        }

        // Min-heap storing {edge_weight, {node, parent_node}}
        // We always want to pick the smallest edge_weight next
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        int cost = 0; // total weight of MST built so far

        // isMST[i] = true once node i has been finalized into the MST
        vector<bool> isMST(V, false);

        // Start from node 0, with weight 0 and no parent (-1)
        pq.push({0, {0, -1}});

        while (!pq.empty()) {
            auto [wt, p] = pq.top();
            auto [u, par] = p; // 'par' = parent node (not used further, but useful if reconstructing the tree)
            pq.pop();

            // If this node is already part of the MST, skip (stale/duplicate entry)
            if (isMST[u]) continue;

            // Add node u to the MST
            isMST[u] = true;
            cost += wt;

            // Push all edges from u that lead to nodes not yet in the MST
            for (auto [v, weight] : graph[u]) {
                if (!isMST[v]) {
                    pq.push({weight, {v, u}});
                }
            }
        }

        // Total weight of the Minimum Spanning Tree
        return cost;
    }
};

/*
    GFG - Spanning Tree (Prim's Algorithm)
    ---------------------------------------
    Problem: Given a weighted undirected graph with V vertices and edges,
    find the sum of weights of edges in the Minimum Spanning Tree (MST).

    Approach: Prim's Algorithm (Greedy + Min-Heap)
    ------------------------------------------------
    - Start from any vertex (vertex 0 here).
    - Always pick the minimum weight edge that connects
      a vertex inside MST to a vertex outside MST.
    - Use a min-heap (priority queue) to efficiently get
      the minimum weight edge at each step.
    - Stop when all V vertices are included in MST.

    Why Prim's here?
    - Graph is given as edge list -> easy to build adjacency list
    - Works well for dense graphs
    - Similar structure to Dijkstra's algorithm

    Time:  O((V + E) log V) -> each edge pushed/popped from heap once
    Space: O(V + E)         -> adjacency list + heap + isMST array
*/

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edge list
        // Each entry: {neighbor, weight}
        // Graph is undirected -> add both directions
        vector<vector<pair<int,int>>> graph(V);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        // isMST[i] = true means vertex i is already
        // included in the MST (its minimum edge is finalized)
        vector<bool> isMST(V, false);
        int total = 0;   // accumulated MST weight

        // Min-heap: {edge_weight, vertex}
        // Smallest weight edge always on top
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<>> pq;

        // Step 2: Start from vertex 0
        // Push {weight=0, vertex=0} as the seed
        // (0 weight because no edge needed to include the first vertex)
        pq.push({0, 0});

        // Step 3: Greedily expand MST one vertex at a time
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            // Skip if already part of MST
            // (a vertex can be pushed multiple times with different weights,
            //  we only process it the first time -> with minimum weight)
            if (isMST[u]) continue;

            // Include vertex u in MST
            isMST[u] = true;
            total += wt;   // add this edge's weight to MST total

            // Step 4: Explore neighbors of u
            // Push all neighbors not yet in MST into the heap
            // They are candidates for the next MST expansion
            for (auto [v, w] : graph[u]) {
                if (!isMST[v]) 
                    pq.push({w, v});
            }
        }

        // total now holds the minimum sum of edge weights
        // that connects all V vertices (MST weight)
        return total;
    }
};

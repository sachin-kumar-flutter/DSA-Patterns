// User function Template for C++
class Solution {
  public:
    /*
        Bellman-Ford Algorithm
        ------------------------
        Finds shortest distances from a source vertex to all other vertices
        in a weighted graph, even with negative edge weights.
        Detects negative weight cycles in the same pass.

        Time Complexity : O(V * E)
        Space Complexity: O(V)
    */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // Step 1: Initialize all distances as "infinity" (1e8),
        // except the source, which is 0.
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Step 2: Run V iterations instead of V-1.
        // - Iterations 0 to V-2: normal edge relaxation
        //   (guaranteed enough passes for correct shortest paths,
        //    since the longest simple path has at most V-1 edges).
        // - Iteration V-1 (the extra pass): acts as the negative-cycle check.
        //   If any edge can still be relaxed here, a negative cycle exists.
        for (int i = 0; i < V; i++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int weight = e[2];
                
                if (dist[u] != (int)1e8 && dist[u] + weight < dist[v]) {
                    // If we're still relaxing on the V-th pass,
                    // it means there's a negative weight cycle.
                    if (i == V - 1) return {-1};
                    
                    // Otherwise, normal relaxation: update shortest distance.
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        // Step 3: All distances are finalized and no negative cycle exists.
        return dist;
    }
};

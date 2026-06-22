class Solution {
public:
    /*
        Approach: 
        1. Compute degree of every vertex.
        2. Count vertices with ODD degree.
           - For Euler Circuit  → odd degree count must be 0
           - For Euler Path     → odd degree count must be exactly 2
           - Anything else      → neither exists
        3. Check graph connectivity using DFS 
           (only considering vertices that have at least one edge,
            since isolated/degree-0 vertices don't affect Euler path/circuit).
        4. Based on odd degree count, return:
              0 -> no Euler path or circuit
              1 -> Euler path exists
              2 -> Euler circuit exists
    */
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        int oddDegree = 0;
        vector<int> degree(V);

        // Step 1: calculate degree of each vertex
        // and count how many vertices have odd degree
        for (int i = 0; i < V; i++) {
            degree[i] = adj[i].size();
            if (degree[i] % 2 == 1) 
                oddDegree++;
        }

        // Step 2: Euler path/circuit can only exist if
        // odd degree count is 0 (circuit) or 2 (path).
        // Any other count means it's impossible.
        if (oddDegree != 2 && oddDegree != 0) 
            return 0;

        // Step 3: check connectivity via DFS
        // Start DFS from any vertex that has at least one edge
        // (skip isolated vertices with degree 0 — they don't matter)
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (degree[i] != 0) {
                dfs(i, visited, adj);
                break;  // only need one DFS call from any valid start
            }
        }

        // Step 4: after DFS, every vertex with degree > 0
        // must have been visited. If any non-isolated vertex
        // was NOT visited, the graph is disconnected
        // -> Euler path/circuit impossible
        for (int i = 0; i < V; i++) {
            if (degree[i] && !visited[i]) 
                return 0;
        }

        // Step 5: graph is connected and odd-degree condition is satisfied
        // oddDegree == 0 -> Euler Circuit exists
        // oddDegree == 2 -> Euler Path exists
        if (oddDegree == 0) 
            return 2;   // Euler Circuit
        else 
            return 1;   // Euler Path
    }

    // Standard recursive DFS to check connectivity
    // Visits all vertices reachable from 'node'
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) 
                dfs(neighbour, visited, adj);
        }
    }
};

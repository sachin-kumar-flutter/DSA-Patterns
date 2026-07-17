/*
    GFG - Hamiltonian Path
    ----------------------
    Problem: Given an undirected graph with n vertices and m edges,
    check if a Hamiltonian Path exists.

    Hamiltonian Path: a path that visits EVERY vertex exactly once.
    (Unlike Euler Path which uses every EDGE once)

    Approach: DFS Backtracking
    --------------------------
    - Try starting DFS from every vertex.
    - Track count of visited vertices.
    - If count reaches n → all vertices visited → Hamiltonian Path found.
    - If current path doesn't lead to solution → BACKTRACK
      (unvisit the node, decrement count, try another neighbour).

    Why Backtracking?
    - No polynomial algorithm exists (NP-Complete problem).
    - Must try all possible paths exhaustively.
    - Backtracking prunes dead ends early.

    Time:  O(n!) — worst case, try all permutations of vertices
    Space: O(n)  — visited array + recursion stack
*/

class Solution {
public:
    bool check(int n, int m, vector<vector<int>> edges) {
        // Step 1: Build undirected adjacency list (1-indexed)
        vector<vector<int>> graph(n + 1);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n + 1, false);
        int count = 0;

        // Step 2: Try starting Hamiltonian Path from every vertex
        // (path can start from any vertex, so try all)
        for (int i = 1; i <= n; i++) {
            if (dfs(i, n, count, graph, visited))
                return true;    // found a valid Hamiltonian Path
        }

        return false;   // no Hamiltonian Path exists
    }

    // Returns true if Hamiltonian Path found starting from 'node'
    bool dfs(int node, int n, int& count,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        // Mark current node as visited and include in path
        visited[node] = true;
        count++;

        // Base case: all n vertices visited → Hamiltonian Path found
        if (count == n) return true;

        // Explore all unvisited neighbours
        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, n, count, graph, visited))
                    return true;    // propagate success upward
            }
        }

        // BACKTRACK: current path didn't lead to solution
        // unvisit this node so other paths can use it
        count--;
        visited[node] = false;
        return false;
    }
};

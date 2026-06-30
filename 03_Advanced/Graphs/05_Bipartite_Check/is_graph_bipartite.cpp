// LeetCode 785 - Is Graph Bipartite?
//
// Problem: A graph is bipartite if its nodes can be split into 2 groups such
// that every edge connects nodes from DIFFERENT groups (no edge stays within
// the same group). Determine if the given graph is bipartite.
//
// Core idea: try to 2-color the graph (colors 0 and 1) such that every node's
// neighbors get the OPPOSITE color. If at any point two adjacent nodes end up
// with the SAME color, the graph cannot be bipartite.
//
// Both BFS and DFS achieve this 2-coloring - just different traversal orders.
// Outer loop handles disconnected components (graph may not be fully connected).

// ============================================================
// Approach 1: BFS
// Time: O(V + E), Space: O(V)
// ============================================================

class SolutionBFS {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0/1 = the two groups

        // check every component separately (graph may be disconnected)
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !bfs(i, graph, color)) return false;
        }

        return true;
    }

    bool bfs(int src, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> q;
        q.push(src);
        color[src] = 0; // arbitrarily start this component with color 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : graph[node]) {
                if (color[neighbour] == -1) {
                    // uncolored neighbour -> assign the OPPOSITE color of current node
                    color[neighbour] = 1 - color[node];
                    q.push(neighbour);
                } else if (color[neighbour] == color[node]) {
                    // neighbour already has the SAME color as current node -> conflict, not bipartite
                    return false;
                }
                // if neighbour already has the opposite color, nothing to do - already consistent
            }
        }

        return true;
    }
};

// ============================================================
// Approach 2: DFS
// Time: O(V + E), Space: O(V)
// ============================================================

class SolutionDFS {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        // check every component separately (graph may be disconnected)
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(i, 0, graph, color)) return false;
        }

        return true;
    }

    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int> &color) {
        color[node] = c; // assign current node this color

        for (int neighbour : graph[node]) {
            if (color[neighbour] == c) {
                // neighbour has the SAME color as current node -> conflict, not bipartite
                return false;
            } else if (color[neighbour] == -1 && !dfs(neighbour, 1 - c, graph, color)) {
                // uncolored neighbour -> recurse with the OPPOSITE color;
                // propagate failure up if a conflict is found deeper in the recursion
                return false;
            }
            // if neighbour already has the opposite color, nothing to do - already consistent
        }

        return true;
    }
};

/*
NOTES (for revision):

1. This is the "2-coloring" pattern - functionally similar in spirit to cycle
   detection, but instead of tracking "currently on this path" (gray/black),
   you're tracking which of 2 groups each node belongs to.

2. The outer loop (`for i in 0..n`) is essential and easy to forget - the graph
   can have multiple disconnected components, and each one needs its own
   independent check (a single BFS/DFS from node 0 won't reach nodes in a
   separate component).

3. `1 - color[node]` is a neat trick to flip between 0 and 1 without an if-else -
   worth keeping as your default idiom for any 2-coloring/bipartite problem.

4. Odd-length cycles are the underlying reason a graph fails to be bipartite -
   if you trace through a cycle with odd length, the alternating coloring
   forces two adjacent nodes to end up with the same color, triggering the
   conflict check. Good one-liner to have ready if asked "why" in an interview.
*/

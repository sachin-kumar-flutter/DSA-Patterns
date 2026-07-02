// LeetCode 886 - Possible Bipartition
//
// Problem: Given n people and a list of dislikes pairs, determine if everyone
// can be split into two groups such that no two people who dislike each other
// are in the same group.
//
// This is IDENTICAL to "Is Graph Bipartite?" (785) in disguise:
// - people = nodes
// - dislikes = edges (people who dislike each other must be in DIFFERENT groups)
// - "can we split into 2 groups" = "can we 2-color this graph"
//
// Recognizing this mapping is the actual skill being tested here, not the
// algorithm itself - the code is a direct reuse of the bipartite check pattern.
//
// Graph is 1-indexed (nodes 1 to n), so all arrays are size n+1.

// ============================================================
// Approach 1: DFS (3-color style, adapted for 2-coloring)
// Time: O(V + E), Space: O(V + E)
// ============================================================

class SolutionDFS {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1); // 1-indexed adjacency list
        vector<int> color(n + 1, -1);    // -1 = uncolored, 0/1 = two groups

        // build undirected graph from dislikes pairs
        // if A dislikes B, they must be in different groups -> edge between them
        for (auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        // check every component (graph may be disconnected)
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1 && !dfs(i, 0, color, graph)) return false;
        }

        return true;
    }

    bool dfs(int node, int c, vector<int> &color, vector<vector<int>> &graph) {
        color[node] = c; // assign this person to group c

        for (int neighbour : graph[node]) {
            if (color[neighbour] == c) {
                // neighbour has same color as current node -> they dislike each other
                // but are in the same group -> impossible
                return false;
            } else if (color[neighbour] == -1 && !dfs(neighbour, 1 - c, color, graph)) {
                // uncolored neighbour -> assign opposite group and recurse
                // propagate failure up if conflict found deeper
                return false;
            }
            // if neighbour already has the opposite color -> consistent, nothing to do
        }

        return true;
    }
};

// ============================================================
// Approach 2: BFS
// Time: O(V + E), Space: O(V + E)
// ============================================================

class SolutionBFS {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> color(n + 1, -1);

        for (auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        // check every component separately
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0; // seed this component with group 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbour : graph[node]) {
                        if (color[neighbour] == -1) {
                            // uncolored -> assign opposite group and enqueue
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        } else if (color[neighbour] == color[node]) {
                            // same group as current node -> conflict, impossible
                            return false;
                        }
                        // opposite color already assigned -> consistent, skip
                    }
                }
            }
        }

        return true;
    }
};

/*
NOTES (for revision):

1. Problem mapping is the key insight: "split into 2 groups with no conflicts"
   = "2-color the graph with no same-color edges" = bipartite check.
   The algorithm is identical to 785 - only the graph construction differs.

2. Compared to 785 where the graph is given directly, here you BUILD the graph
   from dislikes pairs first. Both are undirected (if A dislikes B, B dislikes A).

3. 1-indexed nodes (1 to n) -> arrays of size n+1. Easy off-by-one bug if you
   forget this and use size n like in 785 where nodes are 0-indexed.

4. The outer loop starting from i=1 (not i=0) handles disconnected components -
   people with no dislikes are isolated nodes, reachable only from themselves.
   They're trivially placeable in either group, so skipping them (already colored
   from a previous component's DFS/BFS) is fine.

5. Cross-reference: 785_is_graph_bipartite.cpp in this folder - same algorithm,
   this problem just adds a graph-construction step before the bipartite check.
*/

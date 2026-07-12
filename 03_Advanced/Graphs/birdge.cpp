/*
    LC 1192 - Critical Connections in a Network (Hard)
    ---------------------------------------------------
    Problem: Given a network of n servers and connections between them,
    find all critical connections (bridges) — edges whose removal
    disconnects the network (increases number of components).

    Approach: Tarjan's Bridge Finding Algorithm
    -------------------------------------------
    Uses two key arrays tracked during DFS:
        disc[u] = discovery time of node u
                  (timestamp when u was first visited)

        low[u]  = lowest discovery time reachable from
                  subtree rooted at u via back edges
                  (earliest ancestor u's subtree can reach)

    Bridge Condition for a tree edge (u, v):
        low[v] > disc[u]
        → v's subtree has NO back edge reaching u or above
        → removing (u,v) completely disconnects v's subtree
        → (u,v) is a bridge

    Key Insight:
        Edges inside a cycle are NEVER bridges
        because alternate paths exist.
        Only edges with no alternate route are bridges.

    Time:  O(V + E) — single DFS pass visits every node and edge once
    Space: O(V + E) — graph + disc/low arrays + recursion stack
*/

class Solution {
public:
    int count = 0;   // global timer to assign discovery timestamps

    vector<vector<int>> criticalConnections(int n,
                         vector<vector<int>>& connections) {
        // Step 1: Build undirected adjacency list
        vector<vector<int>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        // disc[i] = discovery time of node i (-1 = unvisited)
        // low[i]  = lowest disc time reachable from subtree of i
        vector<int> disc(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> bridges;

        // Step 2: Run DFS from every unvisited node
        // (handles disconnected graphs — though this problem guarantees
        //  a connected graph, this makes code more general)
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1)
                dfs(i, -1, graph, bridges, disc, low);
        }

        return bridges;
    }

    void dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<vector<int>>& bridges,
             vector<int>& disc,
             vector<int>& low) {

        // stamp current node with discovery time and initial low value
        // both start equal — low gets updated as we find back edges
        disc[node] = low[node] = count++;

        for (int& neighbour : graph[node]) {

            // Case 1: skip the edge we came from
            // (parent edge is not a back edge in undirected graph)
            if (neighbour == parent) continue;

            // Case 2: neighbour not yet visited → tree edge
            // recurse deeper into the DFS tree
            else if (disc[neighbour] == -1) {
                dfs(neighbour, node, graph, bridges, disc, low);

                // after returning from child, pull up the lowest
                // reachable disc time discovered in child's subtree
                low[node] = min(low[node], low[neighbour]);

                // BRIDGE CONDITION:
                // if child's subtree cannot reach node or above
                // (low[neighbour] > disc[node])
                // then this edge is the only connection → it's a bridge
                if (low[neighbour] > disc[node])
                    bridges.push_back({node, neighbour});
            }

            // Case 3: neighbour already visited and not parent → back edge
            // we found a path to an ancestor
            // update low[node] — this is what PREVENTS bridges
            // (a cycle exists, so this edge is not critical)
            else {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }
};

// LeetCode 802 - Find Eventual Safe States
//
// Problem: A node is "safe" if every possible path starting from it eventually
// terminates (i.e., no path from it can lead into a cycle). Return all safe nodes.
//
// Two approaches below. BFS (reverse Kahn's) is the recommended/primary version -
// it's iterative, avoids recursion stack risk on deep graphs, and is the more
// "robust for an interview" answer. DFS 3-color is the more commonly taught
// version (same idea as Course Schedule's cycle detection) - included for comparison.

// ============================================================
// Approach 1 (RECOMMENDED): BFS - Kahn's Algorithm on Reversed Graph
// Time: O(V + E), Space: O(V + E)
// ============================================================

class SolutionBFS {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);       // reversed graph: adj[neighbour] -> original nodes pointing to it
        vector<int> outdegree(n, 0);      // out-degree in the ORIGINAL graph direction

        // build reverse graph + track original out-degree in one pass
        for (int i = 0; i < n; i++) {
            for (int neighbour : graph[i]) {
                adj[neighbour].push_back(i); // reverse edge: neighbour -> i
                outdegree[i]++;
            }
        }

        queue<int> q;
        // terminal nodes (no outgoing edges) are trivially safe -> safe starting points
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true; // confirmed: every path from this node terminates safely

            // for every node that points INTO `node`, one of its risky outgoing
            // edges just got confirmed safe -> decrement its remaining out-degree
            for (int neighbour : adj[node]) {
                if (--outdegree[neighbour] == 0) {
                    // ALL of neighbour's outgoing edges are now confirmed safe
                    // -> neighbour itself is safe
                    q.push(neighbour);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i]) ans.push_back(i); // result must be in sorted order - already is, since i increases
        }
        return ans;
    }
};

// ============================================================
// Approach 2: DFS - 3-Color Cycle Detection
// Time: O(V + E), Space: O(V + E)
//
// Color states:
//   0 = unvisited (white)  - never explored
//   1 = visiting (gray)    - currently in the recursion stack (active path)
//   2 = safe (black)       - fully explored, confirmed no cycle reachable from here
// ============================================================

class SolutionDFS {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, color)) ans.push_back(i);
        }
        return ans; // already sorted since i increases from 0 to n-1
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color) {
        if (color[node] == 2) return true;   // already confirmed safe
        if (color[node] == 1) return false;  // currently in active path -> cycle found, unsafe

        color[node] = 1; // mark as "in progress" for this path

        for (int neighbour : graph[node]) {
            if (!dfs(neighbour, graph, color)) return false; // any unsafe neighbour makes this node unsafe
        }

        color[node] = 2; // every outgoing path explored safely -> mark confirmed safe
        return true;
    }
};

/*
NOTES (for revision):

1. Core safety condition: a node is safe ONLY IF all of its outgoing paths
   terminate without hitting a cycle. A terminal node (no outgoing edges) is
   safe by definition - that's the base case both approaches start from.

2. BFS version works BACKWARD from terminal nodes using the REVERSED graph +
   out-degree (mirrors standard Kahn's algorithm, which uses in-degree on the
   original graph). A node is pushed to the queue only once ALL of its outgoing
   edges have been confirmed safe (outdegree hits 0) - that IS the safety condition.

3. DFS version works FORWARD from each node, same 3-color cycle detection used
   in Course Schedule (207) - gray = currently on this path (cycle if revisited),
   black = fully explored and safe.

4. Why BFS is the more robust pick: DFS recursion depth can reach O(V) on a long
   chain graph, risking stack overflow on large inputs. BFS is iterative, so it
   has no such risk - same time complexity, safer in practice.

5. This problem is the cycle-detection pattern in disguise: "safe node" is just
   another way of phrasing "no cycle is reachable from this node."
*/

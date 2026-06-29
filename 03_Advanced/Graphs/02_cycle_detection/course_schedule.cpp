// LeetCode 207 - Course Schedule
//
// Problem: Given numCourses and a list of prerequisite pairs [a, b] (meaning
// "to take course a, you must first take course b"), determine if it's possible
// to finish all courses.
//
// Core insight: this is fundamentally a CYCLE DETECTION problem in a directed graph.
// It is only impossible to finish all courses if the prerequisite graph contains a
// cycle (e.g., A needs B, B needs A -> deadlock, neither can ever be taken).
//
// Two ways to detect that cycle below:
//   1. BFS (Kahn's Algorithm) - this is actually the standard TOPOLOGICAL SORT
//      algorithm, repurposed here: if we can process all nodes via topological
//      order, no cycle exists. (Useful to revisit when solving Course Schedule II,
//      which asks for the actual order - same algorithm, just collect `topo` as output.)
//   2. DFS (3-color cycle detection) - directly detects a cycle by tracking each
//      node's state during the current recursion path.

// ============================================================
// Approach 1: BFS - Kahn's Algorithm (Topological Sort)
// Time: O(V + E), Space: O(V + E)
// ============================================================

class SolutionBFS {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // build graph: edge from prerequisite -> course that depends on it
        // (p[1] must be taken before p[0], so p[1] -> p[0])
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++; // course p[0] now has one more prerequisite
        }

        queue<int> q;
        // start with all courses that have NO prerequisites - they can be taken immediately
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo; // tracks the order in which courses get "unlocked"

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // taking `node` removes it as a blocker for its dependent courses
            for (int neighbour : graph[node]) {
                if (--indegree[neighbour] == 0) {
                    // neighbour's last prerequisite just got satisfied -> can be taken now
                    q.push(neighbour);
                }
            }
        }

        // if topo includes every course, no cycle existed and all courses are completable.
        // if some courses never reached indegree 0, they're stuck in a cycle -> impossible.
        return topo.size() == numCourses;
    }
};

// ============================================================
// Approach 2: DFS - 3-Color Cycle Detection
// Time: O(V + E), Space: O(V + E)
//
// Color states:
//   0 = unvisited (white)   - never explored
//   1 = visiting (gray)     - currently in the recursion stack (active path)
//   2 = visited (black)     - fully explored, confirmed safe (no cycle through it)
// ============================================================

class SolutionDFS {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> color(numCourses, 0);

        for (auto &p : prerequisites) graph[p[1]].push_back(p[0]);

        // try DFS from every unvisited node (graph may have multiple disconnected components)
        for (int i = 0; i < numCourses; i++) {
            if (!color[i] && !dfs(i, graph, color)) return false;
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color) {
        color[node] = 1; // mark as "currently being explored" (in active recursion path)

        for (int neighbour : graph[node]) {
            // if neighbour is gray (already in the CURRENT path), we've looped back -> cycle found
            if (color[neighbour] == 1) return false;

            // if neighbour is white (unvisited), recurse into it; propagate failure if it hits a cycle
            if (!color[neighbour] && !dfs(neighbour, graph, color)) return false;

            // if neighbour is black (color == 2), it's already fully explored and safe - skip it
        }

        color[node] = 2; // done exploring this node's entire subtree safely, mark fully visited
        return true;
    }
};

/*
NOTES (for revision):

1. Why 3 colors and not just a simple visited[] boolean array?
   A plain visited[] can't distinguish "currently on this path" (gray) from
   "fully explored, safe, on a totally different path" (black). Without that
   distinction, you'd get false positives when two separate paths happen to
   reach the same already-explored node (which is fine), versus a node
   actually looping back onto itself within the same path (which is a cycle).

2. BFS (Kahn's) detects a cycle INDIRECTLY - if nodes are stuck in a cycle,
   their indegree never drops to 0, so they're never pushed to the queue,
   so topo.size() ends up less than numCourses.

3. DFS detects a cycle DIRECTLY - the moment you re-encounter a gray node
   (one still in your current recursion path), you know you've looped back.

4. This problem's BFS solution IS the topological sort algorithm. When solving
   Course Schedule II (output the actual order), reuse this exact BFS code -
   the only change is returning `topo` instead of just checking its size.
*/

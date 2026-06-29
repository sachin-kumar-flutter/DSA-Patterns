// LeetCode 210 - Course Schedule II
//
// Same as Course Schedule (207), but instead of just checking feasibility,
// we now need to return the actual valid order of courses.
// This is Kahn's Algorithm (BFS topological sort) - identical logic to 207's
// BFS solution, with `topo`/`ans` now being the real output, not just a size check.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        // build graph: edge from prerequisite -> course that depends on it
        // (p[1] must be taken before p[0], so p[1] -> p[0])
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++; // course p[0] now has one more prerequisite
        }

        queue<int> q;
        vector<int> ans; // stores the actual topological order (valid course sequence)

        // start with all courses that have NO prerequisites - they can be taken first
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node); // this course can be safely taken next

            // taking `node` removes it as a blocker for its dependent courses
            for (int neighbour : graph[node]) {
                if (--indegree[neighbour] == 0) {
                    // neighbour's last prerequisite just got satisfied -> can be taken now
                    q.push(neighbour);
                }
            }
        }

        // if ans includes every course, it's a valid order.
        // if some courses never reached indegree 0, they're stuck in a cycle ->
        // no valid order exists, return empty vector as per problem's requirement.
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};

/*
NOTES (for revision):

1. This is LITERALLY the BFS solution from Course Schedule (207), with one
   difference: 207 only checks topo.size() == numCourses (boolean answer),
   while this returns `ans` itself (the actual order) when valid.

2. The order returned is A valid order, not THE unique order - if multiple
   courses have indegree 0 at the same time, their relative order in `ans`
   depends on queue insertion order, and any of those orderings is acceptable
   per the problem (LeetCode accepts any valid topological order).

3. Cycle handling is identical to 207: if a cycle exists, some courses never
   reach indegree 0, never get pushed, and ans.size() < numCourses -> return {}.

4. Good problem to confirm you've internalized: detecting a cycle (207) and
   producing a topological order (210) aren't two different algorithms -
   they're the same algorithm, just reading a different piece of its output.
*/

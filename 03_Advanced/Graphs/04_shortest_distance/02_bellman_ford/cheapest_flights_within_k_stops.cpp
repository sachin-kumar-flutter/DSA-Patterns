// LeetCode 787 - Cheapest Flights Within K Stops
//
// Problem: Find the cheapest price from src to dst using at most k stops
// (k stops = k+1 edges). Return -1 if no such route exists.
//
// Why Bellman-Ford and NOT Dijkstra here:
// Dijkstra finds the globally shortest path with no edge-count constraint.
// Here, we need the cheapest path using AT MOST k+1 edges - a path with
// more edges but lower total cost should NOT be considered if it exceeds
// the stop limit. Dijkstra has no natural way to enforce that edge-count
// constraint. Bellman-Ford naturally fits because one "iteration" = exactly
// one more edge added to the path, so stopping after k+1 iterations
// enforces the k-stop limit directly.
//
// Core idea: run Bellman-Ford for exactly (k+1) iterations (not V-1 like
// standard Bellman-Ford). Each iteration i finds the cheapest path using
// AT MOST i edges. After k+1 iterations, dist[dst] = cheapest price
// reachable within k stops.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; // cost to reach source is 0

        // run exactly k+1 iterations (k stops = k+1 edges)
        for (int i = 0; i <= k; i++) {
            // CRITICAL: copy dist into temp BEFORE processing this iteration's edges.
            // This ensures we only use paths built in PREVIOUS iterations when
            // relaxing edges in the CURRENT iteration.
            // Without this, a single iteration could chain multiple edges together
            // (e.g., relax A->B, then immediately use that updated B to relax B->C),
            // which would mean using 2 edges in one iteration - violating the
            // "at most k stops" constraint.
            vector<int> temp = dist;

            for (auto &f : flights) {
                int u = f[0]; // source of this flight
                int v = f[1]; // destination of this flight
                int wt = f[2]; // cost of this flight

                // only relax if u is reachable (dist[u] != INT_MAX avoids overflow)
                if (dist[u] != INT_MAX) {
                    temp[v] = min(wt + dist[u], temp[v]);
                }
            }

            dist = temp; // commit this iteration's updates
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

/*
NOTES (for revision):

1. The `temp` array trick is the most important detail in this solution.
   Standard Bellman-Ford relaxes edges in-place (updating dist[] directly),
   which is fine when you want shortest path with no edge-count limit.
   Here, in-place updates would let a single iteration chain multiple edges,
   silently exceeding the k-stop constraint without any error.
   Using temp = snapshot of dist at the START of each iteration fixes this -
   each iteration can only extend paths by exactly 1 more edge.

2. This is a CONSTRAINED shortest path problem - the constraint (at most k
   edges) is what rules out Dijkstra and makes Bellman-Ford the right tool.
   Key interview signal: whenever you see "at most k steps/hops/stops", think
   Bellman-Ford with exactly k+1 iterations, not Dijkstra.

3. Iteration count: k stops = k+1 edges = k+1 Bellman-Ford iterations.
   Off-by-one here (using i < k instead of i <= k) is the single most common
   bug on this problem - double check this boundary every time.

4. Standard Bellman-Ford runs V-1 iterations to find shortest paths (and a
   V-th iteration to detect negative cycles). This problem runs exactly k+1
   iterations by design - it's Bellman-Ford with an early stop, not the full
   algorithm.
*/

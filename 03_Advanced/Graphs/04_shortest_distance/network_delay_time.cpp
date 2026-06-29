// LeetCode 743 - Network Delay Time
//
// Problem: A signal starts at node k and travels through a network of directed,
// weighted edges (times[i] = [source, target, travel_time]). Find the time for
// the signal to reach ALL n nodes, or -1 if some node is unreachable.
//
// This is a direct application of Dijkstra's algorithm: single source (k),
// non-negative weights, find shortest distance to every other node, then
// the answer is simply the MAXIMUM of those shortest distances (since we need
// ALL nodes to receive the signal, the slowest one determines total time).

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list: graph[u] = list of (v, weight) pairs for edges u -> v
        vector<vector<pair<int,int>>> graph(n + 1); // 1-indexed nodes, so size n+1
        for (auto &t : times) graph[t[0]].push_back({t[1], t[2]});

        // min-heap ordered by distance (smallest distance popped first)
        // pair = {current_known_distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k}); // distance to source itself is 0

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // stale entry check: if this distance is worse than what we've already
            // found for `node`, skip it (a shorter path was already processed)
            if (d > dist[node]) continue;

            // relax all outgoing edges from `node`
            for (auto [neighbour, wt] : graph[node]) {
                int newDist = wt + dist[node];

                // found a shorter path to `neighbour` -> update and push to heap
                if (newDist < dist[neighbour]) {
                    dist[neighbour] = newDist;
                    pq.push({newDist, neighbour});
                }
            }
        }

        int ans = 0;
        // the answer is the time for the SLOWEST node to receive the signal -
        // i.e., the maximum shortest-distance across all nodes
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }

        // if any node is still unreachable (dist stayed INT_MAX), return -1
        return ans == INT_MAX ? -1 : ans;
    }
};

/*
NOTES (for revision):

1. Why max() and not sum() of distances: the signal travels to all nodes
   SIMULTANEOUSLY (parallel propagation through the network), not sequentially.
   So the total time is bounded by whichever node takes the LONGEST to reach,
   not the sum of all individual distances.

2. The "stale entry" check (`if (d > dist[node]) continue;`) is essential for
   correctness with a standard priority_queue, since C++'s pq doesn't support
   efficient "decrease-key" - we just push duplicates and skip outdated ones
   when popped. Without this check, you could still get a correct answer here
   since `newDist < dist[neighbour]` already filters bad updates, but the
   check avoids wasted work re-processing already-finalized nodes.

3. Graph is 1-indexed (`n+1` size), matching node labels 1 to n on this problem -
   double check this convention since 0-indexed graph problems are far more common.

4. This is the canonical "vanilla Dijkstra" template - reuse this exact
   structure (graph build + min-heap + stale check + relax) for any single-source
   shortest path problem with non-negative weights.
*/

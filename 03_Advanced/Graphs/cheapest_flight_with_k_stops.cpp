class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dist[i] = cheapest cost to reach node i so far
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Run exactly k+1 passes (k stops = k+1 edges)
        for (int i = 0; i <= k; i++) {
            // IMPORTANT: copy dist so we only use previous pass's values
            vector<int> temp = dist;

            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], wt = flight[2];

                // skip if u itself is unreachable in previous pass
                if (dist[u] == INT_MAX) continue;

                if (dist[u] + wt < temp[v]) {
                    temp[v] = dist[u] + wt;
                }
            }

            dist = temp; // move to next pass using this pass's results
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

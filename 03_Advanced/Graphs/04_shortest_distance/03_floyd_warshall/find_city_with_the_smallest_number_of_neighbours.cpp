// LeetCode 1334 - Find the City With the Smallest Number of Neighbors at a Threshold Distance
//
// Problem: Given n cities and weighted bidirectional edges, find the city that
// has the fewest other cities reachable within distanceThreshold. If there's a
// tie, return the city with the greater index.
//
// Why Floyd-Warshall and NOT Dijkstra/Bellman-Ford:
// We need shortest distances between ALL pairs of cities (not just from one
// source), because we're comparing reachability counts across EVERY city.
// Running Dijkstra n times would also work (O(n * E log V)), but Floyd-Warshall
// is cleaner here since n is small (n <= 100) and all-pairs is exactly its
// purpose. This is the canonical Floyd-Warshall signal: small graph + all-pairs.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // dist[i][j] = shortest known distance between city i and city j
        // initialize to INT_MAX (unreachable) for all pairs
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // distance from any city to itself is 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // populate direct edge weights (graph is bidirectional)
        for (auto &e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Floyd-Warshall: for every intermediate city k, check if routing
        // through k gives a shorter path between every pair (i, j)
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // guard against INT_MAX + INT_MAX overflow
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minCityCount = n + 1; // worst possible reachable count + 1
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int count = 0; // number of cities reachable from i within threshold

            for (int j = 0; j < n; j++) {
                if (j != i && dist[i][j] <= distanceThreshold) count++;
            }

            // use <= (not <) so that in case of a tie, the higher-indexed city
            // overwrites the answer - problem guarantees return the greater index on tie
            if (count <= minCityCount) {
                minCityCount = count;
                ans = i;
            }
        }

        return ans;
    }
};

/*
NOTES (for revision):

1. Floyd-Warshall signal: ALL-PAIRS shortest path on a SMALL graph (n <= ~400).
   The moment a problem asks about distances between every possible pair of nodes
   and n is small, Floyd-Warshall is cleaner than running Dijkstra n times.

2. The overflow guard (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) is
   critical - adding anything to INT_MAX causes integer overflow and produces
   a negative number, silently corrupting all distance comparisons. Never skip
   this check in Floyd-Warshall.

3. The `<=` in `if (count <= minCityCount)` is the tie-breaking mechanism.
   Since i increases from 0 to n-1, a later city (higher index) naturally

class Solution {
  public:
    // Floyd-Warshall Algorithm: finds shortest distances between every pair of vertices
    // Time Complexity: O(V^3), Space Complexity: O(1) extra (modifies dist matrix in-place)
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size(); // number of vertices

        // k = intermediate vertex being considered for the path
        for(int k=0; k<n; k++){
            // i = source vertex
            for(int i=0; i<n; i++){
                // j = destination vertex
                for(int j=0; j<n; j++){
                    // Only relax if both i->k and k->j paths exist (not unreachable)
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8){
                        // Update dist[i][j] if going through k gives a shorter path
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        // After all iterations, dist[i][j] holds the shortest distance from i to j
        // (1e8 in the result means j is unreachable from i)
    }
};

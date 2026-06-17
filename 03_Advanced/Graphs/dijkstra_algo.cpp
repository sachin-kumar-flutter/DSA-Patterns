class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list from edge list.
        // edges[i] = {u, v, weight} -> undirected weighted graph
        vector<vector<pair<int,int>>> graph(V);
        for(auto &e:edges){
            graph[e[0]].push_back({e[1],e[2]}); // u -> v with weight
            graph[e[1]].push_back({e[0],e[2]}); // v -> u with weight (undirected)
        }
        
        // Min-heap of {distance, node}, ordered by smallest distance first
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // dist[i] = shortest distance from src to node i (initially "infinity")
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src}); // start from source with distance 0
        
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            
            // Stale entry check: if we already found a shorter path to `node`
            // before this entry was processed, skip it (lazy deletion).
            if(d>dist[node]) continue;
            
            // Relax all edges from current node
            for(auto [neighbour,weight]:graph[node]){
                int newDist=weight+dist[node];
                
                // If going through `node` gives a shorter path to `neighbour`, update it
                if(newDist<dist[neighbour]){
                    pq.push({newDist,neighbour});
                    dist[neighbour]=newDist;
                }
            }
        }
        
        return dist; // dist[i] holds shortest distance from src to i (INT_MAX if unreachable)
    }
};

/*
Time Complexity: O((V + E) log V) — each edge relaxation can push to the heap,
                 and heap operations cost O(log V).
Space Complexity: O(V + E) — adjacency list + distance array + priority queue.

Note: This works only for graphs with non-negative edge weights.
For graphs with negative weights, use Bellman-Ford instead.
*/

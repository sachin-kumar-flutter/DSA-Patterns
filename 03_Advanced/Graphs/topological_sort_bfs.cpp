/*
-------------------------------------
🧩 Problem: Topological Sort (Kahn's Algorithm)
📂 Category: Graph / Topological Sort
🧠 Concept:
- Breadth First Search
- Indegree Tracking
- DAG Processing

⚡ Approach:
- Compute indegree of every node
- Push all nodes with indegree 0
  into queue
- Remove nodes one by one
- Reduce indegree of neighbors
- Push newly unlocked nodes

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V)

Where:
- V = Vertices
- E = Edges

🎯 Key Idea:
- A node can be processed only when
  all its prerequisites are completed

-------------------------------------
*/

class Solution {
public:

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);

        // Build graph
        for(auto& edge : edges) graph[edge[0]].push_back(edge[1]);

        // Compute indegrees
        for(int node = 0;node < V;node++) {
            for(int neighbour : graph[node]) indegree[neighbour]++;
        }
        queue<int> bfsQueue;

        // Start with indegree 0 nodes
        for(int node = 0;node < V;node++) {
            if(indegree[node] == 0) bfsQueue.push(node);
        }

        vector<int> topoOrder;

        while(!bfsQueue.empty()) {

            int node = bfsQueue.front();
            bfsQueue.pop();
            topoOrder.push_back(node);

            for(int neighbour : graph[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) bfsQueue.push(neighbour);
            }
        }

        return topoOrder;
    }
};

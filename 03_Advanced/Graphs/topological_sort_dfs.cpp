/*
-------------------------------------
🧩 Problem: Topological Sort (DFS)
📂 Category: Graph / Topological Sort
🧠 Concept:
- Depth First Search
- DAG Traversal
- Postorder Processing

⚡ Approach:
- Perform DFS on every node
- Visit all dependencies first
- Push node into stack after
  processing its neighbors
- Reverse finishing order gives
  topological ordering

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V)

Where:
- V = Vertices
- E = Edges

🎯 Key Idea:
- A node is added only after
  all its outgoing neighbors
  are processed

-------------------------------------
*/

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> graph(V);
        // Build adjacency list
        for(auto& edge : edges) graph[edge[0]].push_back(edge[1]);

        vector<bool> visited(V, false);
        stack<int> topoStack;

        // DFS from every component
        for(int node = 0; node < V; node++) if(!visited[node]) dfs(node, graph, visited, topoStack);

        vector<int> topoOrder;

        while(!topoStack.empty()) {

            topoOrder.push_back(topoStack.top());
            topoStack.pop();
        }

        return topoOrder;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topoStack) {

        visited[node] = true;

        for(int neighbour : graph[node])  if(!visited[neighbour]) dfs(neighbour, graph, visited, topoStack);

        // Postorder insertion
        topoStack.push(node);
    }
};

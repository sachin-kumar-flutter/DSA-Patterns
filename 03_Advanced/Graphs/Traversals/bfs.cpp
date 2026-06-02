/*
-------------------------------------
🧩 Problem: BFS of Graph
📂 Category: Graph / Traversal
🧠 Concept: Breadth First Search (BFS)

⚡ Approach:
- Start from source node (0)
- Use queue to process nodes level-by-level
- Visit each neighbor exactly once
- Mark nodes as visited before pushing

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V)

Where:
- V = Number of vertices
- E = Number of edges

🎯 Key Idea:
- BFS explores nearest nodes first

-------------------------------------
*/

class Solution {
public:

    vector<int> bfs(vector<vector<int>>& adj) {

        int totalNodes = adj.size();

        vector<bool> visited(totalNodes, false);
        vector<int> traversalOrder;
        queue<int> bfsQueue;

        // Start BFS from node 0
        bfsQueue.push(0);
        visited[0] = true;

        while(!bfsQueue.empty()) {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();
            traversalOrder.push_back(currentNode);

            for(int neighbor : adj[currentNode]) {

                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }

        return traversalOrder;
    }
};

/*
-------------------------------------
🧩 Problem: Number of Provinces
📂 Category: Graph / Connected Components
🧠 Concept:
- Depth First Search
- Connected Components
- Adjacency Matrix Traversal

⚡ Approach:
- Treat each city as a graph node
- Traverse all directly and indirectly
  connected cities using DFS
- Each new DFS call represents
  a new province

⏱️ Time Complexity: O(n²)
💾 Space Complexity: O(n)

Where:
- n = number of cities

🎯 Key Idea:
- Number of connected components
  equals number of provinces

-------------------------------------
*/

class Solution {
public:

    int findCircleNum(
        vector<vector<int>>& isConnected) {

        int totalCities = isConnected.size();

        vector<bool> visited(totalCities, false);
        int provinces = 0;

        for(int city = 0; city < totalCities; city++) {
            if(!visited[city]) {
                provinces++;
                dfs(isConnected, visited, city);
            }
        }

        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {

        visited[city] = true;

        for(int neighbor = 0; neighbor < isConnected.size(); neighbor++) {

            if(isConnected[city][neighbor] == 1 && !visited[neighbor]) dfs(isConnected, visited, neighbor);
        }
    }
};

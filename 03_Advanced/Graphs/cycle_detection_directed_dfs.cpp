
/*
-------------------------------------
🧩 Problem: Cycle Detection in Directed Graph
📂 Category: Graph / Cycle Detection
🧠 Concept:
- DFS
- Recursion Path Tracking
- 3-Color Technique

⚡ Approach:
- White (0) = Unvisited
- Gray  (1) = In current DFS path
- Black (2) = Fully processed

- If a Gray node is encountered,
  a back edge exists and
  a cycle is found

⏱️ Time Complexity: O(V + E)
💾 Space Complexity: O(V)

🎯 Key Idea:
- Cycle exists if DFS reaches a node
  already present in the current path

-------------------------------------
*/

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> graph(V);
        
        for(auto &e:edges) graph[e[0]].push_back(e[1]);
    
        vector<int> color(V,0);
        
        for(int i=0;i<V;i++) if(!color[i]) if(dfs(i,graph,color)) return true;
        
        return false;
    }
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &color){
        color[node]=1;
        
        for(int neighbour:graph[node]){
            if(color[neighbour]==1) return true;
            
            if(color[neighbour]==0) if(dfs(neighbour,graph,color)) return true;
        }
        
        color[node]=2;
        return false;
    }
};

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        
        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,graph,visited)) return true;
            }
        }
        return false;
    }
    bool dfs(int node,int parent,vector<vector<int>> &graph,vector<bool>& visited){
        visited[node]=true;
        
        for(int neighbour:graph[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,node,graph,visited)) return true;
            }
            else if(neighbour!=parent) return true;
        }
        
        return false;
    }
};

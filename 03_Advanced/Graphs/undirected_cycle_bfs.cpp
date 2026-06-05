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
                if(bfs(i,graph,visited)) return true;
            }
        }
        return false;
    }
    bool bfs(int x,vector<vector<int>> &graph,vector<bool>& visited){
        queue<pair<int,int>> q;
        q.push({x,-1});
        visited[x]=true;
        
        while(!q.empty()){
            auto [node,parent]=q.front();
            q.pop();
    
            for(int neighbour:graph[node]){
                if(!visited[neighbour]){
                    q.push({neighbour,node});
                    visited[neighbour]=true;
                }
                else if(neighbour!=parent) return true;
            }
        }
        
        return false;
    }
};

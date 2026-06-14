class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> graph(n);
        vector<int> color(n,0);
        for(auto &p:prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        
        vector<int> result;
        
        
        for(int i=0;i<n;i++){
            if(color[i]==0 && !dfs(graph,color,result,i)) return {};
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
    
    bool dfs(vector<vector<int>> &graph,vector<int> &color,vector<int> &result,int node){
        color[node]=1;
        
        for(int neighbour:graph[node]){
            if(color[neighbour]==0 && !dfs(graph,color,result,neighbour)) return false;
            if(color[neighbour]==1) return false;
        }
        
        result.push_back(node);
        return true;
    }
};

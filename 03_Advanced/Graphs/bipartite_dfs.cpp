class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1)  if(!dfs(i,0,graph,color)) return false;
        }

        return true;
    }
    bool dfs(int src,int c, vector<vector<int>> &graph,vector<int> &color){
        color[src]=c;

        for(int neighbour:graph[src]){
            if(color[neighbour]==-1 && !dfs(neighbour,1-c,graph,color)) return false;
            else if(color[neighbour]==c) return false;
        }

        return true;

    }
};

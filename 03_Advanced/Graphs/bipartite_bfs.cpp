class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfsCheck(i,graph,color)) return false;
            }
        }

        return true;
    }
    bool bfsCheck(int src,vector<vector<int>> &graph,vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int neighbour:graph[node]){
                if(color[neighbour]==-1){
                    color[neighbour]=1-color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[node]) return false;
            }
        }

        return true;
    }
};

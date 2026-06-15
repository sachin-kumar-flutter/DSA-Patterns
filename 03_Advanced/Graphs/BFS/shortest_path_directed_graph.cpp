class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> graph(V);
        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(src);
        vector<int> ans(V,-1);
        ans[src]=0;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            level++;
            
            while(size--){
                int node=q.front();
                q.pop();
                
                for(int neighbour:graph[node]){
                    if(ans[neighbour]==-1){
                        q.push(neighbour);
                        ans[neighbour]=level;
                    }
                }
            }
        }
        
        return ans;
    }
};

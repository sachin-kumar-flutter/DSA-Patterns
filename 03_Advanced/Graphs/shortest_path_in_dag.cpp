// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> graph(V);
        for(auto &e:edges) graph[e[0]].push_back(make_pair(e[1],e[2]));
        
        stack<int> st;
        vector<bool> visited(V);
        
        dfs(0,graph,st,visited);
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto a:graph[node]){
                int neighbour=a.first;
                int weight=a.second;
                dist[neighbour]=min(dist[neighbour],weight+dist[node]);
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
    
    void dfs(int node,vector<vector<pair<int,int>>> &graph,stack<int> &st,vector<bool> &visited){
        visited[node]=1;
        
        for(auto n:graph[node]){
            if(!visited[n.first]) dfs(n.first,graph,st,visited);
        }
        
        st.push(node);
    }
};

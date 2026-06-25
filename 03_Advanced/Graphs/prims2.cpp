class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<V-1;i++){
            for(int j=i+1;j<V;j++){
                int dist=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                graph[i].push_back({j,dist});
                graph[j].push_back({i,dist});
            }
        }

        vector<bool> isMST(V,false);
        int ans=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [wt,u]=pq.top();
            pq.pop();
            if(isMST[u]) continue;

            ans+=wt;
            isMST[u]=true;

            for(auto [v,weight]:graph[u]){
                if(!isMST[v]) pq.push({weight,v});
            }
        }

        return ans;
    }
};

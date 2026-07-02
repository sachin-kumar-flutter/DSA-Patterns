class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));
        dist[0][0]=0;

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto [effort,x,y]=pq.top();
            pq.pop();

            if(x==rows-1 && y==cols-1) return effort;
            if(effort>dist[x][y]) continue;

            for(auto d:dir){
                int nx=d.first+x;
                int ny=d.second+y;

                if(nx<0 || nx>=rows || ny<0 || ny>=cols) continue;
                int newEfforts=max(effort,abs(heights[nx][ny]-heights[x][y]));

                if(newEfforts<dist[nx][ny]){
                    dist[nx][ny]=newEfforts;
                    pq.push({newEfforts,nx,ny});
                }
            }
        }

        return dist[rows-1][cols-1];
    }
};

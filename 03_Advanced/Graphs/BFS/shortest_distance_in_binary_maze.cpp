class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int rows=mat.size();
        int cols=mat[0].size();
        
        if(mat[src[0]][src[1]]==0) return -1;
        if(mat[dest[0]][dest[1]]==0) return -1;
        if(src[0]==dest[0] && src[1]==dest[1]) return 0;
        
        queue<pair<int,int>> q;
        q.push({src[0],src[1]});
        mat[src[0]][src[1]]=0;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        
        int steps=0;
        
        while(!q.empty()){
            int size=q.size();
            steps++;
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                
                for(auto &d:dir){
                    int nx=d.first+x;
                    int ny=d.second+y;
                    
                    if(nx<0 || nx>=rows || ny>=cols || ny<0 || mat[nx][ny]==0) continue;
                    if(nx==dest[0] && ny==dest[1]) return steps;
                    
                    mat[nx][ny]=0;
                    q.push({nx,ny});
                    
                }
            }
        }
        
        return -1;
    }
};

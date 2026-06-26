class DSU {
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        size.assign(n,1);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return false;
        if(size[px]<size[py]) swap(px,py);
        parent[py]=px;
        size[px]+=size[py];
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        DSU dsu(rows*cols);
        int islands=0;
        vector<pair<int,int>> dir={{0,1},{1,0}};

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;

                    for(auto d:dir){
                        int nx=d.first+i;
                        int ny=d.second+j;

                        if(nx<rows && ny<cols && grid[nx][ny]=='1') {
                            if(dsu.unite(i*cols+j,nx*cols+ny)) islands--;
                        }
                    }
                }
            }
        }

        return islands;

    }
};

// Problem: Rotting Oranges
// Pattern: Graph + Multi-Source BFS
// Difficulty: Medium

// Key Idea:
// All rotten oranges simultaneously spread rot to adjacent fresh oranges.
// This can be modeled as a multi-source BFS problem.

// Intuition:
// - Treat all initially rotten oranges as sources
// - Spread rot level by level (like BFS levels)
// - Each level represents one minute
// - Continue until no fresh oranges remain

// Approach:
// - Count total fresh oranges
// - Push all rotten oranges into queue (multi-source BFS)
// - Perform BFS:
//     • For each level → process all current rotten oranges
//     • Infect adjacent fresh oranges
//     • Decrease fresh count
// - Track time (minutes) for each level

// Why BFS?
// BFS naturally models shortest time (minimum steps)
// required to spread the infection across the grid

// Edge Case:
// If fresh oranges remain after BFS → return -1

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

// Tags: Graph, BFS, Matrix, Multi-Source BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: Count fresh oranges and store rotten ones
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        // Directions for 4-neighbour traversal
        int dir[4][2] = {
            {1,0},   // down
            {-1,0},  // up
            {0,1},   // right
            {0,-1}   // left
        };
        
        int minutes = 0;
        
        // Step 2: BFS traversal
        while(!q.empty() && fresh > 0){
            
            int size = q.size();
            
            while(size--){
                
                auto [x,y] = q.front();
                q.pop();
                
                // Explore 4 directions
                for(auto &d : dir){
                    
                    int nx = x + d[0];
                    int ny = y + d[1];
                    
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                        
                        grid[nx][ny] = 2;   // rot the orange
                        fresh--;
                        
                        q.push({nx,ny});
                    }
                }
            }
            
            minutes++;
        }
        
        // If fresh oranges remain → impossible
        return fresh == 0 ? minutes : -1;
    }
};

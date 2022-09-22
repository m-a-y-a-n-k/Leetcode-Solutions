class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> vis;
    
    void flood(vector<vector<int>>& grid, int r, int c, int n, int m){
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || grid[r][c]){
            return ;
        }
        vis[r][c] = 1;
        grid[r][c] = 1;
        
        for(int k = 0; k < 4; ++k){
            int x = r + dir[k][0], y = c + dir[k][1];
            flood(grid, x, y, n, m);
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for(int r = 0; r < n; ++r){
            if(!vis[r][0] && !grid[r][0]){
                flood(grid, r, 0, n, m);
            }
            if(!vis[r][m-1] && !grid[r][m-1]){
                flood(grid, r, m-1, n, m);
            }
        }
        for(int c = 0; c < m; ++c){
            if(!vis[0][c] && !grid[0][c]){
                flood(grid, 0, c, n, m);
            }
            if(!vis[n-1][c] && !grid[n-1][c]){
                flood(grid, n-1, c, n, m);
            }
        }
        
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        
        int ans = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(!vis[r][c] && !grid[r][c]){
                    ans++;
                    flood(grid, r, c, n, m);
                }
            }
        }
        
        return ans;
    }
};
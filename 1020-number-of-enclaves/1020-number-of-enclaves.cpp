class Solution {
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int filled;
    vector<vector<bool>> vis;
    
    int fill(vector<vector<int>>& grid, int r, int c, int n, int m){
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || !grid[r][c]){
            return 0;
        }
        vis[r][c] = true;
        grid[r][c] = 0;
        int ans = 1;
        
        for(int k = 0; k < 4; ++k){
            int x = r + dir[k][0], y = c + dir[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !grid[x][y]){
                continue;
            }
            ans += fill(grid, x, y, n, m);
        }
        
        return ans;
    }
        
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        int ans = 0;
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        
        vector<int> rowB = {0, n - 1}, colB = {0, m - 1};
        
        for(int i = 0; i < n; ++i){
            for(int k = 0; k < 2; ++k){
                if(grid[i][colB[k]] && !vis[i][colB[k]]){
                    fill(grid, i, colB[k], n, m);
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int k = 0; k < 2; ++k){
                if(grid[rowB[k]][i] && !vis[rowB[k]][i]){
                    fill(grid, rowB[k], i, n, m);
                }
            }
        }

        filled = 0;
        
        for(int i = 1; i < n - 1; ++i){
            for(int j = 1; j < m - 1; ++j){
                if(grid[i][j] && !vis[i][j]){
                    filled += fill(grid, i, j, n, m);
                }
            }
        }

        return filled;
    }
};
class Solution {
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> vis;
    
    void flood(vector<vector<int>> &grid, int r, int c, int n, int m){
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || !grid[r][c]){
            return ;
        }
        
        vis[r][c] = true;
        grid[r][c] = 0;
        
        for(int k = 0; k < 4; ++k){
            int x = r + dir[k][0], y = c + dir[k][1];
            flood(grid, x, y, n, m);
        }
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = size(grid1), m = size(grid1[0]);
        int ans = 0;
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && !grid1[i][j] && grid2[i][j]){
                    flood(grid2, i, j, n, m);
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid2[i][j]){
                    ans++;
                    flood(grid2, i, j, n, m);
                }
            }
        }
            
        return ans;
    }
};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<bool>> vis;

class Solution {
    
    bool unsafe(int r, int c, int n, int m){
       return r < 0 || r >= n || c < 0 || c >= m; 
    }
    
    void flood(vector<vector<int>>& grid, int r, int c, int n, int m){
        if(unsafe(r,c,n,m) || vis[r][c] || grid[r][c]){
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
        
        vector<int> rowB = {0, n-1}, colB = {0, m-1};
        for(int r = 0; r < n; ++r){
            for(auto &c: colB){
                if(!grid[r][c] && !vis[r][c]){
                    flood(grid, r, c, n, m);
                }
            }
        }
        for(int c = 0; c < m; ++c){
            for(auto &r: rowB){
                if(!grid[r][c] && !vis[r][c]){
                    flood(grid, r, c, n, m);
                }
            }
        }
        
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        
        int ans = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(!grid[r][c] && !vis[r][c]){
                    ans++;
                    flood(grid, r, c, n, m);
                }
            }
        }
        
        return ans;
    }
};
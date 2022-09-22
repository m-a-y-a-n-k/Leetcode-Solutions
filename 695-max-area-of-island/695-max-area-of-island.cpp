class Solution {
    int dis[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    int util(
        vector<vector<int>>& grid, vector<vector<bool>>& vis, 
        int r, int c, int n, int m
    ){
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || !grid[r][c]){
            return 0;
        }
        vis[r][c] = 1;
        int ans = 1;
        for(int d = 0; d < 4; d++){
            int x = r + dis[d][0], y = c + dis[d][1];
            ans += util(grid, vis, x, y, n , m);
        }
        return ans;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(grid[r][c] == 1){
                    ans = max(ans, util(grid, vis, r, c, n, m));
                }
            }
        }
        return ans;
    }
};